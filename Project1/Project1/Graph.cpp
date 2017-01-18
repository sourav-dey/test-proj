#include "Graph.h"

Graph::Graph( int numberOfVertices )
	: numberOfVertices( numberOfVertices )
{
	adj = new list<int>[numberOfVertices];
}

void Graph::addEdge(int src, int des) const
{
	adj[src].push_back( des );
}

void Graph::BFS(int src) const
{
	// Create a bool array to denote visited/unvisited
	bool *arrVisited = new bool[numberOfVertices];

	// initially set everything to false
	for ( int i = 0; i < numberOfVertices; ++i )
	{
		arrVisited[i] = false;
	}

	queue<int> BFSQueue;

	BFSQueue.push( src );
	arrVisited[src] = true;

	while( !BFSQueue.empty() )
	{
		int vertex = BFSQueue.front( );

		cout<<vertex<<" ";

		BFSQueue.pop( );

		for ( auto it = adj[vertex].begin(); it != adj[vertex].end(); ++it )
		{
			if ( arrVisited[*it] == false )
			{
				BFSQueue.push( *it );
				arrVisited[*it] = true;
			}
		}
	}
	delete[] arrVisited;
}

void Graph::DFSRecursive(int src) const
{
	// Create a bool array to denote visited/unvisited
	bool *arrVisited = new bool[numberOfVertices];

	// initially set everything to false
	for ( int i = 0; i < numberOfVertices; ++i )
	{
		arrVisited[i] = false;
	}

	DFSRecursive( src, arrVisited );

	// For disconnected graph
	for ( int i = 0; i < numberOfVertices; ++i )
	{
		if (!arrVisited[i])
		{
			DFSRecursive( i, arrVisited );
		}
	}
	delete[] arrVisited;
}

void Graph::DFSRecursive(int src, bool *arrVisited) const
{
	cout << src << " ";
	arrVisited[src] = true;

	for( auto it = adj[src].begin(); it != adj[src].end(); ++it )
	{
		if ( !arrVisited[src] )
		{
			DFSRecursive( src, arrVisited );
		}
	}
}

void Graph::DFSIterative(int src, bool* arrVisited) const
{
	stack<int> stackDFS;

	stackDFS.push( src );
	arrVisited[src] = true;

	while(!stackDFS.empty() )
	{
		int vertex = stackDFS.top( );
		printf( "%d ", vertex );
		stackDFS.pop( );

		for ( auto it = adj[vertex].rbegin(); it != adj[vertex].rend(); ++it )
		{
			if ( !arrVisited[*it] )
			{
				stackDFS.push( *it );
				arrVisited[*it] = true;
			}
		}
	}
}

void Graph::DFSIterative(int src) const
{
	// Create a bool array to denote visited/unvisited
	bool *arrVisited = new bool[numberOfVertices];

	// initially set everything to false
	for ( int i = 0; i < numberOfVertices; ++i )
	{
		arrVisited[i] = false;
	}

	DFSIterative(src, arrVisited);

	// For disjoint graph
	for ( int i = 0; i < numberOfVertices; ++i )
	{
		if ( !arrVisited[i] )
		{
			DFSIterative( i, arrVisited );
		}
	}
	delete[] arrVisited;
}

Graph::~Graph()
{
	delete[] adj;
}
