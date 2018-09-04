/*
 * This code is a combination of two sources, with very slight modifications.
 * The original memoization code is taken from here: https://github.com/jimporter/memo
 * I have taken the hash function for tuples from here:
 * https://stackoverflow.com/questions/7110301/generic-hash-for-tuples-in-unordered-map-unordered-set
 * This lets us use a std::unordered_map, rather than a std::map, which in my testing is approximately 2x faster.
 */

#ifndef INC_MEMO_MEMOIZER_HPP
#define INC_MEMO_MEMOIZER_HPP

#include <functional>
#include <type_traits>
#include <unordered_map>

using std::conditional;
using std::declval;
using std::enable_if;
using std::forward;
using std::forward_as_tuple;
using std::get;
using std::is_class;
using std::is_same;
using std::move;
using std::remove_const;
using std::remove_reference;
using std::tuple;
using std::tuple_size;
using std::unordered_map;

namespace memo {

namespace detail {
// This gets the base function type from pretty much anything it can:
// C function types, member function types, monomorphic function objects.
template <typename T, typename Enable = void>
struct function_signature;

template <typename T>
struct function_signature<T, typename enable_if<is_class<T>::value>::type>
    : function_signature<decltype( &T::operator() )> {};

template <typename T, typename Ret, typename... Args>
struct function_signature<Ret ( T::* )( Args... )> {
  using type = Ret( Args... );
};

template <typename T, typename Ret, typename... Args>
struct function_signature<Ret ( T::* )( Args... ) const> {
  using type = Ret( Args... );
};

template <typename Ret, typename... Args>
struct function_signature<Ret( Args... )> {
  using type = Ret( Args... );
};

template <typename Ret, typename... Args>
struct function_signature<Ret ( & )( Args... )> {
  using type = Ret( Args... );
};

template <typename Ret, typename... Args>
struct function_signature<Ret ( * )( Args... )> {
  using type = Ret( Args... );
};

template <typename T>
struct remove_const_ref : remove_const<typename remove_reference<T>::type> {};

template <typename T, typename U>
struct is_same_base_type : is_same<typename remove_const_ref<T>::type, typename remove_const_ref<U>::type> {};
} // namespace detail

template <typename TT>
struct hash {
  size_t operator()( TT const &tt ) const {
    return std::hash<TT>()( tt );
  }
};

template <class T>
inline void hash_combine( size_t &seed, T const &v ) {
  seed ^= hash<T>()( v ); // + 0x9e3779b9 + ( seed << 6 ) + ( seed >> 2 );
}

template <class Tuple, size_t Index = tuple_size<Tuple>::value - 1>
struct HashValueImpl {
  static void apply( size_t &seed, Tuple const &tuple ) {
    HashValueImpl<Tuple, Index - 1>::apply( seed, tuple );
    hash_combine( seed, get<Index>( tuple ) );
  }
};

template <class Tuple>
struct HashValueImpl<Tuple, 0> {
  static void apply( size_t &seed, Tuple const &tuple ) {
    hash_combine( seed, get<0>( tuple ) );
  }
};

template <typename... TT>
struct hash<tuple<TT...>> {
  size_t operator()( tuple<TT...> const &tt ) const {
    size_t seed = 0;
    HashValueImpl<tuple<TT...>>::apply( seed, tt );
    return seed;
  }
};

template <typename T, typename Function>
class memoizer;

template <typename T, typename Ret, typename... Args>
class memoizer<T, Ret( Args... )> {
public:
  using function_type = Ret( Args... );
  using tuple_type = tuple<typename remove_reference<Args>::type...>;
  using return_type = Ret;
  using return_reference = const return_type &;
  using map_type = unordered_map<tuple_type, return_type, hash<tuple_type>>;

  memoizer() {}
  memoizer( const T &f ) : f_( f ) {}

  template <typename... CallArgs>
  return_reference operator()( CallArgs &&... args ) {
    // This is a roundabout way of requiring that call is called with arguments
    // of the same basic type as the function (i.e. it will make use of
    // automatic conversions for similar types). This ensures that we always
    // call the *same* function for polymorphic function objects.
    return call<typename conditional<detail::is_same_base_type<CallArgs, Args>::value, CallArgs &&,
                                     typename detail::remove_const_ref<Args>::type &&>::type...>(
        forward<CallArgs>( args )... );
  }

private:
  template <typename T2, typename... Args2>
  class can_pass_memoizer {
    template <typename U>
    struct always_bool {
      typedef bool type;
    };

    template <typename T3, typename... Args3>
    static constexpr typename always_bool<decltype( declval<T3>()( declval<memoizer &>(), declval<Args3>()... ) )>::type
    check_( int ) {
      return true;
    }
    template <typename T3, typename... Args3>
    static constexpr bool check_( ... ) {
      return false;
    }

  public:
    static const bool value = check_<T2, Args2...>( 0 );
  };

  template <typename... CallArgs>
  return_reference call( CallArgs &&... args ) {
    auto args_tuple = forward_as_tuple( forward<CallArgs>( args )... );
    auto i = memo_.find( args_tuple );
    if( i != memo_.end() ) {
      return i->second;
    } else {
      auto result = call_function( args... );
      auto ins = memo_.emplace( move( args_tuple ), move( result ) ).first;
      return ins->second;
    }
  }

  template <typename... CallArgs>
  auto call_function( const CallArgs &... args ) ->
      typename enable_if<can_pass_memoizer<T, CallArgs...>::value, return_type>::type {
    return f_( *this, args... );
  }

  template <typename... CallArgs>
  auto call_function( const CallArgs &... args ) ->
      typename enable_if<!can_pass_memoizer<T, CallArgs...>::value, return_type>::type {
    return f_( args... );
  }

  map_type memo_;
  T f_;
};

template <typename Function, typename T>
inline auto memoize( T &&t ) {
  return memoizer<T, Function>( forward<T>( t ) );
}

template <typename T>
inline auto memoize( T &&t ) {
  return memoizer<T, typename detail::function_signature<T>::type>( forward<T>( t ) );
}

} // namespace memo

#endif
