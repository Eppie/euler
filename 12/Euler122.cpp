/*
 * =====================================================================================
 *
 *       Filename:  Euler122.cpp
 *
 *    Description:  Solution to Project Euler, Problem 122
 *
 *        Version:  1.0
 *        Created:  10/10/2018 3:03:50 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  The most naive way of computing n¹⁵ requires fourteen multiplications:
 *                      n × n × ... × n = n¹⁵
 *                  But using a "binary" method you can compute it in six multiplications:
 *                      n × n = n²
 *                      n² × n² = n⁴
 *                      n⁴ × n⁴ = n⁸
 *                      n⁸ × n⁴ = n¹²
 *                      n¹² × n² = n¹⁴
 *                      n¹⁴ × n = n¹⁵
 *                  However it is yet possible to compute it in only five multiplications:
 *                      n × n = n²
 *                      n² × n = n³
 *                      n³ × n³ = n⁶
 *                      n⁶ × n⁶ = n¹²
 *                      n¹² × n³ = n¹⁵
 *                  We shall define m(k) to be the minimum number of multiplications to compute nᵏ; for example m(15) = 5.
 *                  For 1 ≤ k ≤ 200, find ∑ m(k).
 *         Answer:  1582
 *
 * =====================================================================================
 * k = 1 --> 0:
 *   n = n¹
 *
 * k = 2 --> 1:
 *   n × n = n²
 *
 * k = 3 --> 2:
 *   n × n = n²
 *   n² × n = n³
 *
 * k = 4 --> 2:
 *   n × n = n²
 *   n² × n² = n⁴
 */
#include "../helper.hpp"

#define LIMIT 200

namespace euler122 {
// cost[k] will hold the solution for k
auto cost = new uint32_t[LIMIT + 1];
auto path = new uint32_t[LIMIT + 1];

void solve( uint32_t k, uint32_t curPathLen ) {
  cost[k] = curPathLen;
  path[curPathLen] = k;
  for( int i = curPathLen; i >= 0; --i ) {
    if( k + path[i] <= LIMIT && curPathLen + 1 <= cost[k + path[i]] ) {
      solve( k + path[i], curPathLen + 1 );
    }
  }
}
} // namespace euler122

uint32_t solve122() {
  uint32_t result = 0;

  for( int i = 0; i <= LIMIT; ++i ) {
    euler122::cost[i] = LIMIT;
  }

  euler122::solve( 1, 0 );

  for( int i = 1; i <= LIMIT; ++i ) {
    result += euler122::cost[i];
  }

#undef LIMIT

  return result;
}
