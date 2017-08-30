/*
 * =====================================================================================
 *
 *       Filename:  Euler83.cpp
 *
 *    Description:  Solution to Project Euler, Problem 83
 *
 *        Version:  1.1
 *        Created:  5/31/2017 08:50:51 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Andrew Epstein
 *        Problem:  In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by moving left, right, up, and down
 *                  is indicated by asterisks and is equal to 2297.
 *                  131*  673   234*  103*  18*
 *                  201*  96*   342*  965   150*
 *                  630   803   746   422*  111*
 *                  537   699   497   121*  956
 *                  805   732   524   37*   331*
 *                  Find the minimal path sum, in matrix.txt, a 31K text file containing a 80 by 80 matrix,
 *                  from the top left to the bottom right by moving left, right, up, and down.
 *         Answer:  425185
 *
 * =====================================================================================
 */

#include "../helper.hpp"

#define SIZE 80

struct Node {
	uint32_t x;
	uint32_t y;
	uint32_t path_cost;

	Node( uint32_t x_, uint32_t y_, uint32_t path_cost_ ) : x( x_ ), y( y_ ), path_cost( path_cost_ ) {}

	bool operator>( const Node &node ) const {
		return path_cost > node.path_cost;
	}
};

uint32_t solve83() {
	vector<vector<uint32_t>> matrix;

	for( auto && line : loadDataFromFile( "8/matrix.txt", '\n' ) ) {
		vector<uint32_t> elems;
		stringstream ss;
		ss.str( line );
		string item;

		while( getline( ss, item, ',' ) ) {
			elems.push_back( stoi( item ) );
		}

		matrix.push_back( elems );
	}

	// pass in std::greater as the comparison function, so that next.top() will return the minimum element
	priority_queue<Node, vector<Node>, greater<Node>> next;
	vector<vector<bool>> processed( SIZE, vector<bool>( SIZE, false ) );

	next.push( Node( 0, 0, matrix[0][0] ) );

	while( !next.empty() ) {
		Node node = next.top();
		next.pop();

		if( processed[node.y][node.x] ) {
			continue;
		}

		processed[node.y][node.x] = true;

		// At the goal node
		if( node.x == SIZE - 1 && node.y == SIZE - 1 ) {
			return node.path_cost;
		}

		// Add the four surrounding nodes to the queue
		if( node.x + 1 < SIZE ) {
			next.push( Node( node.x + 1, node.y, node.path_cost + matrix[node.y][node.x + 1] ) );
		}

		if( node.y + 1 < SIZE ) {
			next.push( Node( node.x, node.y + 1, node.path_cost + matrix[node.y + 1][node.x] ) );
		}

		if( node.y > 0 ) {
			next.push( Node( node.x, node.y - 1, node.path_cost + matrix[node.y - 1][node.x] ) );
		}

		if( node.x > 0 ) {
			next.push( Node( node.x - 1, node.y, node.path_cost + matrix[node.y][node.x - 1] ) );
		}
	}

	return 0;
}
