#pragma once
#include <iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;

class Graph
{
	int numberOfVertices;
	list<int> *adj;

public:
	Graph( int numberOfVertices );
	void addEdge( int src, int des ) const;
	void BFS( int src ) const;
	void DFSRecursive( int src ) const;
	void DFSRecursive( int src, bool *arrVisitied )const;
	void DFSIterative(int src, bool* arrVisited) const;
	void DFSIterative( int src ) const;
	~Graph( );
};