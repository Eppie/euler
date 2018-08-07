/*
 * =====================================================================================
 *
 *       Filename:  Euler107.cpp
 *
 *    Description:  Solution to Project Euler, Problem 107
 *
 *        Version:  1.0
 *        Created:  3/09/2018 07:27:07 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  See the description here: https://projecteuler.net/problem=107
 *         Answer:  259679
 *
 * =====================================================================================
 */

#include "../helper.hpp"

namespace euler107 {
map<pair<uint32_t, uint32_t>, uint32_t> network;
set<uint32_t> nodes;
uint32_t initialSum = 0;
struct Edge {
	uint32_t from;
	uint32_t to;
	uint32_t weight;

	bool operator<( const Edge& other ) const {
		if( weight != other.weight ) {
			return weight > other.weight;
		}
		if( from != other.from ) {
			return from < other.from;
		}
		return to < other.to;
	}
};

void addEdge( uint32_t from, uint32_t to, uint32_t weight ) {
	initialSum += weight;
	if( from > to ) {
		swap( from, to );
	}
	auto fromTo = make_pair( from, to );
	if( network.count( fromTo ) != 0 ) {
		if( network[fromTo] <= weight ) {
			return;
		}
	}
	network[fromTo] = weight;
	nodes.insert( from );
	nodes.insert( to );
}
}

uint32_t solve107() {
	uint32_t i = 0;
	for( auto && line : loadDataFromFile( "10/network.txt", '\n' ) ) {
		stringstream ss;
		ss.str( line );
		string item;
		uint32_t j = 0;

		while( getline( ss, item, ',' ) ) {
			if( item != "-" && i < j ) {
				//cout << i << ", " << j << ", " << item << endl;
				euler107::addEdge( i, j, stoi( item ) );
			}
			++j;
		}
		++i;
	}

	set<euler107::Edge> minimal;
	set<uint32_t> done;
	done.insert( *euler107::nodes.begin() );
	while( done.size() < euler107::nodes.size() ) {
		priority_queue<euler107::Edge> next;
		for( auto && e : euler107::network ) {
			auto fromTo = e.first;
			bool hasFrom = done.count( fromTo.first ) != 0;
			bool hasTo = done.count( fromTo.second ) != 0;
			if( hasFrom == hasTo ) {
				continue;
			}
			next.push( { fromTo.first, fromTo.second, e.second } );
		}
		auto add = next.top();

		done.insert( add.from );
		done.insert( add.to );
		minimal.insert( add );
	}
	uint32_t optimizedSum = 0;
	for( auto && m : minimal ) {
		optimizedSum += m.weight;
	}
	return euler107::initialSum - optimizedSum;
}
