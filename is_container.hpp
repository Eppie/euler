#include <type_traits>

using std::enable_if;
using std::integral_constant;
using std::is_same;

template <typename T>
struct has_const_iterator {
private:
  typedef struct {
    char array[2];
  } no;

  template <typename C>
  static char test( typename C::const_iterator * );
  template <typename C>
  static no test( ... );

public:
  static const bool value = sizeof( test<T>( 0 ) ) == sizeof( char );
};

template <typename T>
struct has_begin_end {
  template <typename C>
  static char (
      &f( typename enable_if<is_same<decltype( static_cast<typename C::const_iterator ( C::* )() const>( &C::begin ) ),
                                     typename C::const_iterator ( C::* )() const>::value,
                             void>::type * ) )[1];

  template <typename C>
  static char ( &f( ... ) )[2];

  template <typename C>
  static char (
      &g( typename enable_if<is_same<decltype( static_cast<typename C::const_iterator ( C::* )() const>( &C::end ) ),
                                     typename C::const_iterator ( C::* )() const>::value,
                             void>::type * ) )[1];

  template <typename C>
  static char ( &g( ... ) )[2];

  static bool const beg_value = sizeof( f<T>( 0 ) ) == 1;
  static bool const end_value = sizeof( g<T>( 0 ) ) == 1;
};

template <typename T>
struct is_container : integral_constant<bool, has_const_iterator<T>::value && has_begin_end<T>::beg_value
                                                  && has_begin_end<T>::end_value> {};
