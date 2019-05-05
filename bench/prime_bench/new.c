#include <gmp.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

unsigned long ulPrime16[6545]; /* array of 16-bit primes < 65538 */

void vGenPrimesDiv() {
  unsigned long ulN, ul, ul2, ulSqrt, ulDivisor;
  unsigned long nPrimes = 6543;
  unsigned long ulUB = 65537;

  ulPrime16[0] = 0;
  ulPrime16[1] = 2;
  ulPrime16[2] = 3;
  ulPrime16[3] = 5;

  ul = 4;
  ulN = 7;
  while( 1 ) {
    ul2 = 2;
    ulSqrt = ceil( sqrt( ulN + 0.5 ) ); /* faster than integer sqrt */
    while( 1 ) {
      ulDivisor = ulPrime16[ul2++];
      if( ulDivisor >= ulSqrt ) {
        ulPrime16[ul++] = ulN;
        break;
      }
      if( ulN % ulDivisor == 0 ) {
        break;
      }
    }
    ulN += 2;
    if( ( ulN > ulUB ) && ( ul > nPrimes ) ) {
      break;
    }
  }
  ulPrime16[ul] = 0;
}

int iLucasSelfridge( mpz_t mpzN ) {
  /* Test mpzN for primality using Lucas's test with Selfridge's parameters.
   Returns 1 if mpzN is prime or a Lucas-Selfridge pseudoprime. Returns
   0 if mpzN is definitely composite. Note that a Lucas-Selfridge test
   typically requires three to seven times as many bit operations as a
   single Miller's test. The frequency of Lucas-Selfridge pseudoprimes
   appears to be roughly four times that of base-2 strong pseudoprimes;
   the Baillie-PSW test is based on the hope (verified by the author,
   May, 2005, for all N < 10^13; and by Martin Fuller, January, 2007,
   for all N < 10^15) that the two tests have no common pseudoprimes. */

  int iComp2, iP, iJ, iSign;
  long lDabs, lD, lQ;
  unsigned long ulMaxBits, ulNbits, ul, ulGCD;
  mpz_t mpzU, mpzV, mpzNplus1, mpzU2m, mpzV2m, mpzQm, mpz2Qm, mpzT1, mpzT2, mpzT3, mpzT4, mpzD;

#undef RETURN
#define RETURN( n )                                                                                                    \
  {                                                                                                                    \
    mpz_clear( mpzU );                                                                                                 \
    mpz_clear( mpzV );                                                                                                 \
    mpz_clear( mpzNplus1 );                                                                                            \
    mpz_clear( mpzU2m );                                                                                               \
    mpz_clear( mpzV2m );                                                                                               \
    mpz_clear( mpzQm );                                                                                                \
    mpz_clear( mpz2Qm );                                                                                               \
    mpz_clear( mpzT1 );                                                                                                \
    mpz_clear( mpzT2 );                                                                                                \
    mpz_clear( mpzT3 );                                                                                                \
    mpz_clear( mpzT4 );                                                                                                \
    mpz_clear( mpzD );                                                                                                 \
    return ( n );                                                                                                      \
  }

  /* This implementation of the algorithm assumes N is an odd integer > 2,
   so we first eliminate all N < 3 and all even N. As a practical matter,
   we also need to filter out all perfect square values of N, such as
   1093^2 (a base-2 strong pseudoprime); this is because we will later
   require an integer D for which Jacobi(D,N) = -1, and no such integer
   exists if N is a perfect square. The algorithm as written would
   still eventually return zero in this case, but would require
   nearly sqrt(N)/2 iterations. */

  if( mpz_perfect_square_p( mpzN ) ) {
    return ( 0 );
  }

  /* Allocate storage for the mpz_t variables. Most require twice
   the storage of mpzN, since multiplications of order O(mpzN)*O(mpzN)
   will be performed. */

  ulMaxBits = 2 * mpz_sizeinbase( mpzN, 2 ) + mp_bits_per_limb;
  mpz_init2( mpzU, ulMaxBits );
  mpz_init2( mpzV, ulMaxBits );
  mpz_init2( mpzNplus1, ulMaxBits );
  mpz_init2( mpzU2m, ulMaxBits );
  mpz_init2( mpzV2m, ulMaxBits );
  mpz_init2( mpzQm, ulMaxBits );
  mpz_init2( mpz2Qm, ulMaxBits );
  mpz_init2( mpzT1, ulMaxBits );
  mpz_init2( mpzT2, ulMaxBits );
  mpz_init2( mpzT3, ulMaxBits );
  mpz_init2( mpzT4, ulMaxBits );
  mpz_init( mpzD );

  /* Find the first element D in the sequence {5, -7, 9, -11, 13, ...}
   such that Jacobi(D,N) = -1 (Selfridge's algorithm). */

  lDabs = 5;
  iSign = 1;
  while( 1 ) {
    lD = iSign * lDabs;
    iSign = -iSign;
    ulGCD = mpz_gcd_ui( NULL, mpzN, lDabs );
    /* if 1 < GCD < N then N is composite with factor lDabs, and
     Jacobi(D,N) is technically undefined (but often returned
     as zero). */
    if( ( ulGCD > 1 ) && mpz_cmp_ui( mpzN, ulGCD ) > 0 )
      RETURN( 0 );
    mpz_set_si( mpzD, lD );
    iJ = mpz_jacobi( mpzD, mpzN );
    if( iJ == -1 ) {
      break;
    }
    lDabs += 2;
  }

  iP = 1;              /* Selfridge's choice */
  lQ = ( 1 - lD ) / 4; /* Required so D = P*P - 4*Q */

  /* NOTE: The conditions (a) N does not divide Q, and
   (b) D is square-free or not a perfect square, are included by
   some authors; e.g., "Prime numbers and computer methods for
   factorization," Hans Riesel (2nd ed., 1994, Birkhauser, Boston),
   p. 130. For this particular application of Lucas sequences,
   these conditions were found to be immaterial. */

  mpz_add_ui( mpzNplus1, mpzN, 1 ); /* must compute U_(N - Jacobi(D,N)) */

  /* mpzNplus1 is always even, so the accumulated values U and V
   are initialized to U_0 and V_0 (if the target index were odd,
   U and V would be initialized to U_1=1 and V_1=P). In either case,
   the values of U_2m and V_2m are initialized to U_1 and V_1;
   the FOR loop calculates in succession U_2 and V_2, U_4 and
   V_4, U_8 and V_8, etc. If the corresponding bits of N+1 are
   on, these values are then combined with the previous totals
   for U and V, using the composition formulas for addition
   of indices. */

  mpz_set_ui( mpzU, 0 );    /* U=U_0 */
  mpz_set_ui( mpzV, 2 );    /* V=V_0 */
  mpz_set_ui( mpzU2m, 1 );  /* U_1 */
  mpz_set_si( mpzV2m, iP ); /* V_1 */
  mpz_set_si( mpzQm, lQ );
  mpz_set_si( mpz2Qm, 2 * lQ );

  ulNbits = mpz_sizeinbase( mpzNplus1, 2 );
  for( ul = 1; ul < ulNbits; ul++ ) /* zero bit off, already accounted for */
  {
    /* Formulas for doubling of indices (carried out mod N). Note that
     * the indices denoted as "2m" are actually powers of 2, specifically
     * 2^(ul-1) beginning each loop and 2^ul ending each loop.
     *
     * U_2m = U_m*V_m
     * V_2m = V_m*V_m - 2*Q^m
     */
    mpz_mul( mpzU2m, mpzU2m, mpzV2m );
    mpz_mod( mpzU2m, mpzU2m, mpzN );
    mpz_mul( mpzV2m, mpzV2m, mpzV2m );
    mpz_sub( mpzV2m, mpzV2m, mpz2Qm );
    mpz_mod( mpzV2m, mpzV2m, mpzN );
    if( mpz_tstbit( mpzNplus1, ul ) ) {
      /* Formulas for addition of indices (carried out mod N);
       *
       * U_(m+n) = (U_m*V_n + U_n*V_m)/2
       * V_(m+n) = (V_m*V_n + D*U_m*U_n)/2
       *
       * Be careful with division by 2 (mod N)!
       */
      mpz_mul( mpzT1, mpzU2m, mpzV );
      mpz_mul( mpzT2, mpzU, mpzV2m );
      mpz_mul( mpzT3, mpzV2m, mpzV );
      mpz_mul( mpzT4, mpzU2m, mpzU );
      mpz_mul_si( mpzT4, mpzT4, lD );
      mpz_add( mpzU, mpzT1, mpzT2 );
      if( mpz_odd_p( mpzU ) ) {
        mpz_add( mpzU, mpzU, mpzN );
      }
      mpz_fdiv_q_2exp( mpzU, mpzU, 1 );
      mpz_add( mpzV, mpzT3, mpzT4 );
      if( mpz_odd_p( mpzV ) ) {
        mpz_add( mpzV, mpzV, mpzN );
      }
      mpz_fdiv_q_2exp( mpzV, mpzV, 1 );
      mpz_mod( mpzU, mpzU, mpzN );
      mpz_mod( mpzV, mpzV, mpzN );
    }
    /* Calculate Q^m for next bit position, doubling the exponent.
   The irrelevant final iteration is omitted. */
    if( ul < ulNbits - 1 ) /* Q^m not needed for MSB. */
    {
      mpz_mul( mpzQm, mpzQm, mpzQm );
      mpz_mod( mpzQm, mpzQm, mpzN ); /* prevents overflow */
      mpz_add( mpz2Qm, mpzQm, mpzQm );
    }
  }

  /* If U_(N - Jacobi(D,N)) is congruent to 0 mod N, then N is
   a prime or a Lucas pseudoprime; otherwise it is definitely
   composite. */

  if( mpz_sgn( mpzU ) == 0 )
    RETURN( 1 );
  RETURN( 0 );
}

/**********************************************************************/
int iMillerRabin( mpz_t mpzN ) {
  /* Test N for primality using the Miller's strong probable prime
   test with base B. See Gary Miller's famous paper ("Riemann's
   hypothesis and tests for primality," Journal of Computation and
   System Science, 1976, Volume 13, pp 300-317).

   Returns 1 if N is a prime or a base-B strong probable prime.
   Returns 0 if N is definitely not a prime (composite or < 2).

   NOTE 1: Some will not regard this as a "pure" Miller's test with
   base B, since certain adjustments are made, prior to applying the
   algorithm, in order to work around invalid input values and
   improve performance:

   1) N < 3 and even N are screened out first.
   2) Multiples of the small primes (to qMax=# of binary digits in N)
      are returned as composite.
   3) Values of B < 2 are replaced by B=2.
   4) If N divides B exactly, B is replaced by B+1.

   If such adjustments are not made, a third return value (e.g., -1)
   must be allowed, indicating invalid input and an indeterminate result,
   and complicating the calling source code.

   NOTE 2: Not all authorities agree exactly on the conditions for
   Miller's test. Some allow B < 2 (Rosen, "Elementary number theory and
   its applications," 3rd ed., 1993, pp. 195-200), although there are good
   reasons to exclude such values. On the other hand, some require
   1 < B < N (Ribenboim, "The new book of prime number records,"
   3rd ed., 1996, pp. 113-116, 143-146). As far as I know, no one
   allows N to divide B, as this produces "false negatives"; e.g.,
   N=3 and B=6 fails Miller's test, thus indicating N=3 as composite.
   In practice, there appears to be no good reason to use any B < 2,
   and in fact its value is almost always chosen to be a small
   (positive) prime number. Furthermore, in my opinion, refusing to
   first screen out even values of N and N < 3 gratuitously adds
   unnecessary complication to the test.
*/

  static long iFirst = 1;
  static mpz_t mpzB, mpzNm1, mpzd, mpzRem, mpzOne;
  long iBits, s, j;

  /* Allocate the static variables used in Miller's test. */

  if( iFirst ) {
    mpz_init( mpzB ); /* Never needs more than one limb */
    iBits = mp_bits_per_limb * ( 1 + mpz_size( mpzN ) );
    if( iBits < 512 ) {
      iBits = 512;
    }
    mpz_init2( mpzNm1, iBits );
    mpz_init2( mpzOne, iBits );
    mpz_set_si( mpzOne, 1 );
    mpz_init2( mpzd, iBits );
    mpz_init2( mpzRem, 2 * iBits ); /* must contain products */
    iFirst = 0;
  }

  mpz_set_si( mpzB, 2 );

  /* Now compute d and s, where d is odd and N - 1 = (2^s)*d. */

  mpz_sub_ui( mpzNm1, mpzN, 1 );
  s = mpz_scan1( mpzNm1, 0 );
  mpz_tdiv_q_2exp( mpzd, mpzNm1, s );

  /* Now proceed with the Miller's algorithm. First, if B^d is
   congruent to 1 mod N, N is a strong probable prime to base B. */

  mpz_powm( mpzRem, mpzB, mpzd, mpzN );
  if( mpz_cmp_si( mpzRem, 1 ) == 0 ) {
    return ( 1 );
  }

  /* Now calculate B^((2^j)*d), for j=0,1,...,s-1 by successive
   squaring. If any of these is congruent to -1 mod N, N is a
   sprp base B. Start with j=0 and B^d, already computed.
   Miller's test uses repeated modular squaring in place of repeated
   modular exponentiation for speed (squaring is an order of
   magnitude faster). */

  if( mpz_cmp( mpzRem, mpzNm1 ) == 0 ) {
    return ( 1 ); /* j=0 case */
  }
  for( j = 1; j < s; j++ ) {
    mpz_mul( mpzRem, mpzRem, mpzRem );
    mpz_mod( mpzRem, mpzRem, mpzN );
    if( mpz_cmp( mpzRem, mpzNm1 ) == 0 ) {
      return ( 1 );
    }
    if( mpz_cmp( mpzRem, mpzOne ) == 0 ) {
      return ( 0 );
    }
  }

  return ( 0 );
}

unsigned long ulPrmDiv( uint64_t N ) {
  /* Returns the smallest proper prime divisor (p <= ulMaxDivisor) of N.

   If N < 2, return 0.
   If N is prime and "small", return 1. "Small" means N < approximately
     ulMaxDivisor^2.
   If N is prime and "large", return 0. "Large" means N > approximately
     ulMaxDivisor^2.
   If N is composite and its smallest prime divisor p <= ulMaxDivisor,
     return p.
   If N is composite but its smallest prime divisor p > ulMaxDivisor,
     return 0. In this case N will be "large", as above.

   A return of 0 indicates "no conclusion"; N might be < 2
   (questionable input), or N might be "large" (either prime
   or composite) and have no prime divisor p <= ulMaxDivisor.

   A return of 1 indicates that N is a "small" prime.

   A return > 1 indicates that N is composite, and the
   returned value is the smallest proper prime divisor of N.
*/

  unsigned long ul, ulDiv;

  unsigned long ulMaxDivisor = 1000UL;

  double N_sqrt = sqrt( N );

  ul = 2; /* first trial divisor will be 3, the 2nd prime */
  while( 1 ) {
    ulDiv = ulPrime16[ul++];
    if( ulDiv > ulMaxDivisor ) {
      return 0;
    }
    if( N_sqrt < ulDiv ) {
      return 1;
    }
    if( N % ulDiv == 0 ) {
      return ulDiv;
    }
  }
}

int iBPSW( uint64_t N ) {
  unsigned long ulDiv;
  static int first = 1;
  static mpz_t mpzN;

  if( N < 2 ) {
    return 0;
  }

  if( N == 2 ) {
    return 1;
  }

  if( N % 2 == 0 ) {
    return 0;
  }

  ulDiv = ulPrmDiv( N );
  if( ulDiv == 1 ) {
    return ( 1 );
  }
  if( ulDiv > 1 ) {
    return ( 0 );
  }

  if( first ) {
    mpz_init2( mpzN, 64 );
    first = 0;
  }
  mpz_set_ui( mpzN, N );

  if( iMillerRabin( mpzN ) == 0 ) {
    return ( 0 );
  }

  return ( iLucasSelfridge( mpzN ) );
}

/*
int main() {
  uint64_t result = 0;
  vGenPrimesDiv();
  for( uint64_t i = 2; i < 10000000; ++i ) {
    if( iBPSW( i ) ) {
      ++result;
    }
  }
  printf( "result = %lu\n", result );
}
*/
