#include "../AE32_176.cpp"
#include "../AE32_256.cpp"
#include "../AE32_512.cpp"
#include "../AE32_144.cpp"
#include "FJ32_1024.cc"
#include "FJ32_224.cc"
#include "FJ32_256.cc"
#include "MPU_is_prob_prime.h"
#include "bpsw.c"
#include "new.c"
#include "sinclair1.h"
#include "sprp64.h"
#include "worley1.h"
#include <celero/Celero.h>
#include <cstdint>

using celero::DoNotOptimizeAway;

#define NUM_RUNS 3
#define NUM_ITERATIONS 3

bool isPrimeNaive( uint64_t n ) {
  if( n <= 1 ) {
    return false;
  } else if( n <= 3 ) {
    return true;
  } else if( n % 2 == 0 || n % 3 == 0 ) {
    return false;
  }

  uint64_t i = 5;

  while( i * i <= n ) {
    if( n % i == 0 || n % ( i + 2 ) == 0 ) {
      return false;
    }

    i += 6;
  }

  return true;
}

bool witness( uint64_t n, uint64_t s, uint64_t d, uint64_t a ) {
  uint64_t x = 1;

  while( d ) {
    if( d & 1 ) {
      x = ( x * a ) % n;
    }
    a = ( a * a ) % n;
    d >>= 1;
  }

  uint64_t y = 1;

  while( s ) {
    y = ( x * x ) % n;
    if( y == 1 && x != 1 && x != n - 1 ) {
      return false;
    }
    x = y;
    --s;
  }
  if( y != 1 ) {
    return false;
  }
  return true;
}

bool isPrime( uint32_t n ) {
  if( ( ( !( n & 1 ) ) && n != 2 ) || ( n < 2 ) || ( n % 3 == 0 && n != 3 ) ) {
    return false;
  }
  if( n <= 3 ) {
    return true;
  }

  uint64_t d = n / 2;
  uint64_t s = 1;
  while( !( d & 1 ) ) {
    d /= 2;
    ++s;
  }

  if( n < 1373653ULL ) {
    return witness( n, s, d, 2 ) && witness( n, s, d, 3 );
  }

  if( n < 9080191ULL ) {
    return witness( n, s, d, 31 ) && witness( n, s, d, 73 );
  }

  return witness( n, s, d, 2 ) && witness( n, s, d, 7 ) && witness( n, s, d, 61 );
}

class IntFixture : public celero::TestFixture {
public:
  IntFixture() = default;

  virtual std::vector<celero::TestFixture::ExperimentValue> getExperimentValues() const override {
    std::vector<celero::TestFixture::ExperimentValue> problemSpace;

    const int totalNumberOfTests = 32;

    for( int i = 1; i < totalNumberOfTests; i++ ) {
      problemSpace.push_back( {int64_t( pow( 2, i ) )} );
    }

    return problemSpace;
  }

  virtual void setUp( const celero::TestFixture::ExperimentValue &experimentValue ) override {
    this->arrayStart = experimentValue.Value;
    this->array.reserve( this->arraySize );
    this->fill();
    vGenPrimesDiv();
  }

  void fill() {
    for( uint32_t i = 0; i < this->arraySize * 2; i += 2 ) {
      this->array.push_back( this->arrayStart + i + 1 );
    }
  }

  void clear() {
    this->array.clear();
  }

  std::vector<uint32_t> array;
  uint64_t arraySize = 10000;
  uint64_t arrayStart;
};

class SPRPFixture : public celero::TestFixture {
public:
  SPRPFixture() = default;

  virtual std::vector<celero::TestFixture::ExperimentValue> getExperimentValues() const override {
    std::vector<celero::TestFixture::ExperimentValue> problemSpace;

    const int totalNumberOfTests = 32;

    for( int i = 1; i < totalNumberOfTests; i++ ) {
      problemSpace.push_back( {int64_t( pow( 2, i ) )} );
    }

    return problemSpace;
  }

  virtual void setUp( const celero::TestFixture::ExperimentValue &experimentValue ) override {
    this->arrayStart = experimentValue.Value;
    this->array.reserve( this->arraySize );
    this->fill();
    vGenPrimesDiv();
  }

  void fill() {
    uint32_t n = this->arrayStart;
    uint32_t i = 0;
    while( i < this->arraySize ) {
      if( isSPRP( n, 2 ) ) {
        this->array.push_back( n );
        ++i;
      }
      ++n;
    }
  }

  void clear() {
    this->array.clear();
  }

  std::vector<uint32_t> array;
  uint64_t arraySize = 10000;
  uint64_t arrayStart;
};

BASELINE_F( SPRP, isPrimeNaive, SPRPFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( isPrimeNaive( this->array[i] ) );
  }
}

BENCHMARK_F( SPRP, AE32_144, SPRPFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( AE32_144( this->array[i] ) );
  }
}

BENCHMARK_F( SPRP, AE32_176, SPRPFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( AE32_176( this->array[i] ) );
  }
}

BENCHMARK_F( SPRP, MPU_is_prob_prime, SPRPFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( is_prob_prime( this->array[i] ) );
  }
}

BENCHMARK_F( SPRP, iBPSW, SPRPFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( iBPSW( this->array[i] ) );
  }
}

BENCHMARK_F( SPRP, AE32_512, SPRPFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( AE32_512( this->array[i] ) );
  }
}

BENCHMARK_F( SPRP, AE32_256, SPRPFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( AE32_256( this->array[i] ) );
  }
}

BENCHMARK_F( SPRP, bpsw, SPRPFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( BPSW( this->array[i] ) );
  }
}

BENCHMARK_F( SPRP, isPrime, SPRPFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( isPrime( this->array[i] ) );
  }
}

BENCHMARK_F( SPRP, worley, SPRPFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( worley( this->array[i] ) );
  }
}

BENCHMARK_F( SPRP, isPrime1e15, SPRPFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( isPrime1e15( this->array[i] ) );
  }
}

BENCHMARK_F( SPRP, FJ32_224, SPRPFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( FJ32_224( this->array[i] ) );
  }
}

BENCHMARK_F( SPRP, FJ32_256, SPRPFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( FJ32_256( this->array[i] ) );
  }
}

BENCHMARK_F( SPRP, FJ32_1024, SPRPFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( FJ32_1024( this->array[i] ) );
  }
}

BENCHMARK_F( SPRP, efficient_mr64, SPRPFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( efficient_mr64( this->array[i] ) );
  }
}

BASELINE_F( ConsecutiveInts, isPrimeNaive, IntFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( isPrimeNaive( this->array[i] ) );
  }
}

BENCHMARK_F( ConsecutiveInts, AE32_512, IntFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( AE32_512( this->array[i] ) );
  }
}

BENCHMARK_F( ConsecutiveInts, AE32_256, IntFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( AE32_256( this->array[i] ) );
  }
}

BENCHMARK_F( ConsecutiveInts, iBPSW, IntFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( iBPSW( this->array[i] ) );
  }
}

BENCHMARK_F( ConsecutiveInts, bpsw, IntFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( BPSW( this->array[i] ) );
  }
}

BENCHMARK_F( ConsecutiveInts, isPrime, IntFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( isPrime( this->array[i] ) );
  }
}

BENCHMARK_F( ConsecutiveInts, worley, IntFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( worley( this->array[i] ) );
  }
}

BENCHMARK_F( ConsecutiveInts, isPrime1e15, IntFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( isPrime1e15( this->array[i] ) );
  }
}

BENCHMARK_F( ConsecutiveInts, FJ32_224, IntFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( FJ32_224( this->array[i] ) );
  }
}

BENCHMARK_F( ConsecutiveInts, FJ32_256, IntFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( FJ32_256( this->array[i] ) );
  }
}

BENCHMARK_F( ConsecutiveInts, FJ32_1024, IntFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( FJ32_1024( this->array[i] ) );
  }
}

BENCHMARK_F( ConsecutiveInts, efficient_mr64, IntFixture, NUM_RUNS, NUM_ITERATIONS ) {
  for( uint32_t i = 0; i < this->arraySize; ++i ) {
    DoNotOptimizeAway( efficient_mr64( this->array[i] ) );
  }
}

CELERO_MAIN
