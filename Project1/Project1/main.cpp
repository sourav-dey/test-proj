#include<stdio.h>
#include<stdlib.h>
#include <string>
#include<vector>
#include<map>
#include "Graph.h"
#include "Sort.h"
#include "LIS.h"
#include "LongestPlaindrome.h"
#include "BinaryTree.h"
#include "Trie.h"
#include "LinkedList.h"

using namespace std;

class Solution {
public:
	bool isPowerOfFour( int num ) {
		// Find if power of 2
		int x = ( ~num + 1 );

		if ( num != 0 && ( num & ( ~num + 1 ) ) == num  )
		{
			int count = 0;
			while ( num > 1 )
			{
				num = num >> 1;
				++count;
			}

			return count % 2 == 0 ? true : false;
		}
		return false;
	}
};

class DP {
public:
	int numDistinct( string s, string t ) {
		int **count = new int*[t.length( ) + 1];
		for ( int i = 0; i < t.length( ) + 1; ++i )
		{
			count[i] = new int[s.length( ) + 1];
			count[i][0] = 0;
		}

		for ( int j = 0; j < s.length( ) + 1; ++j )
		{
			count[0][j] = 1;
		}

		for ( int i = 0; i < t.length( ); ++i )
		{
			for ( int j = 0; j < s.length( ); ++j )
			{
				if ( t[i] == s[j] )
				{
					count[i+1][j+1] = count[i][j] + count[i+1][j];
				}
				else
				{
					count[i+1][j+1] = count[i+1][j];
				}
			}
		}
		return count[t.length( )][s.length( )];
	}
};

class Duplicate {
public:
	int removeDuplicates( vector<int>& nums ) {
		map<int,int> mapNumDuplicate;

		for ( auto it = nums.begin(); it != nums.end(); )
		{
			if ( mapNumDuplicate.find( *it ) != mapNumDuplicate.end( ) )
			{
				mapNumDuplicate[*it] += 1;

				if ( mapNumDuplicate[*it] > 2 )
				{
					it = nums.erase( it );
				}
				else
				{
					++it;
				}
			}
			else
			{
				mapNumDuplicate[*it] = 1;
				++it;
			}
		}

		int count = 0;
		for ( auto it = mapNumDuplicate.begin( ); it != mapNumDuplicate.end( ); ++it )
		{
			if ( it->second >= 2 )
			{
				count += 2;
			}
			else
			{
				count += it->second;
			}
		}
		return count;
	}

	int removeDupFromSortedArray(vector<int>& nums)
	{
		for (auto i = nums.begin(); i != nums.end(); )
		{
			if ((i +1) != nums.end() && *i == *(i+1))
			{
				nums.erase(i + 1);
			}
			else
			{
				++i;
			}
		}
		return nums.size();
	}
};

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
/*struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode( int x ) : val( x ), left( NULL ), right( NULL ) {}
};

class BinaryTree {
public:
	vector<vector<int>> pathSum( TreeNode* root, int sum ) {
		vector<vector<int>> paths;
		vector<int> path;
		findPaths( root, sum, path, paths );
		return paths;
	}

private:
	void findPaths( TreeNode* node, int sum, vector<int> &path, vector<vector<int>> &paths )
	{
		if ( !node ) return;
		path.push_back( node->val );

		if ( !node->left && !node->right && sum == node->val )
		{
			paths.push_back( path );
		}
		findPaths( node->left, ( sum - node->val ), path, paths );
		findPaths( node->right, ( sum - node->val ), path, paths );
		path.pop_back( );
	}
};*/

/*Q: http://www.geeksforgeeks.org/fill-two-instances-numbers-1-n-specific-way/*/
class FillInstances
{
public:
	void fill( int n ) const
	{
		int *result = new int[2 * n];

		for ( int i = 0; i < 2*n; ++i )
		{
			result[i] = 0;
		}

		if ( fillHelper( result, n, n ) )
		{
			for ( int i = 0; i < 2*n ; ++i )
			{
				printf( "%d", result[i] );
			}
		}
	}

	bool fillHelper( int *result, int curr, int n ) const
	{
		if ( curr == 0 )
		{
			return true;
		}
		for ( int i = 0; i < 2*n - curr - 1; ++i  )
		{
			if ( result[i] == 0 && result[i+curr+1] == 0 )
			{
				result[i] = result[i + curr+1] = curr;
				if ( fillHelper( result, --curr, n ) )
				{
					return true;
				}
				else
				{
					result[i] = result[i + curr+1] = 0;
				}
			}
		}
		return false;
	}
};

class LCS
{
public:
	int doLCS( char *arr, char *arr2, int m, int n )
	{
		int LCS[7][8];
		for ( int i = 0; i <= m; ++i )
		{
			for( int j = 0; j <= n; ++j  )
			{
				if ( i == 0 || j == 0 )
				{
					LCS[i][j] = 0;
				}
				else if ( arr[i-1] == arr2[j-1] )
				{
					LCS[i][j] = LCS[i - 1][j - 1] + 1;
				}
				else
				{
					LCS[i][j] = max( LCS[i - 1][j], LCS[i][j - 1] );
				}
			}
		}
		return LCS[7][8];
	}
};

class CountB {
public:
	vector<int> countBits( int num ) {
		vector<int> *cB = new vector<int>( num + 1 );

		for ( int i = 0; i <= num; ++i )
		{
			( *cB )[i] = ( *cB )[i / 2];
			if ( i % 2 ) ++( *cB )[i];
		}
		return *cB;
	}
};

class LongestPlaindrome1
{
public:
	string longestPlaindrome1(string s )
	{
		if ( s.empty( ) || s.length() == 1 )
			return s;

		int min_start = 0, max_len = 1;
		for ( int i = 0; i < s.length(); )
		{
			if ( s.length() - i <= max_len )
			{
				break;
			}
			int j = i, k = i;
			while ( k < s.length( ) - 1 && s[k + 1] == s[k] )
			{
				++k;
			}
			i = k + 1;
			while( k < s.length() - 1 && s[k+1] == s[j] )
			{
				++k;
				--j;
			}
			int new_length = k - j + 1;
			if ( new_length > max_len )
			{
				max_len = new_length;
				min_start = j;
			}
		}
		return s.substr( min_start, max_len );
	}
};

//Find anagrams in a string
vector<int> findAnagrams(string s, string p)
{
	vector<int> result;

	if (s.length() == 0 || p.length() == 0)
	{
		return result;
	}

	int hash[256] = { 0 };
	int pLength = p.length();
	int sLength = s.length();

	for ( int i = 0; i < pLength; ++i )
	{
		++hash[p[i]];
	}

	int left = 0, right = 0, count = pLength;

	while ( right < s.length())
	{
		if ( --hash[s[right++]] >= 0)
			--count;

		if (count == 0)
			result.push_back(left);

		if ((right - left) == pLength && hash[s[left++]]++ >= 0)
			++count;
	}
	return result;
}

int main( )
{
	/*FillInstances fi;
	fi.fill( 3 );*/

	/*Duplicate dp;
	vector<int> v = { 1,1,1,2,2,3 };
	int z = dp.removeDupFromSortedArray( v );*/

	/*Graph g(4);
	g.addEdge( 0, 1 );
	g.addEdge( 0, 2 );
	g.addEdge( 1, 2 );
	g.addEdge( 2, 0 );
	g.addEdge( 2, 3 );
	g.addEdge( 3, 3 );

	g.BFS( 2 );
	cout << "\n";
	g.DFSRecursive( 2 );
	cout << "\n";
	g.DFSIterative( 2 );
	cout << "\n";*/

//	Sort s;
//	int arr[4] = { 34,1,9,123 };
//	int size = 4;

	//s.selectionSort( arr, size );
	//s.print( arr, size );
//	s.bubbleSort( arr, size );
//	s.insertionSort( arr, size );
//	s.mergeSort( arr, size );
//	s.print( arr, size );

	/*int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof( arr ) / sizeof( arr[0] );

	LIS lis( arr, n );
	int max = lis.doLis( );
	printf( "Max = %d", max );*/

//	char X[] = "AGGTAB";
//	char Y[] = "GXTXAYB";
//
//	int m = strlen( X );
//	int n = strlen( Y );
//	LCS lcs;
//	lcs.doLCS( X, Y, m, n );

	//CountB cb;
	//cb.countBits( 5 );

	/*LongestPlaindrome l1("ababd");
	string ss = l1.doLongestPlaindrome();*/

	/*string s = "aa";
	string p = "bb";

	vector< int> result = findAnagrams(s, p);*/

	/*BinaryTree bt;
	bt.insert(5);
	bt.insert(4);
	bt.insert(3);
	bt.insert(2);
	bt.insert(7);
	bt.insert(6);
	bt.insert(8);

	bt.printInorderBT();
	bt.printPreorderBT();
	bt.printPostorderBT();
	bt.printBFS();
	bt.printDFS();
	bt.deleteKey(7);
	bt.printBFS();
	bt.maxDepth();
	bt.isBstInOrder();

	/*Trie t;
	t.insert("this");
	t.insert("that");
	t.insert("their");
	t.insert("there");
	t.insert("cat");

	bool found = t.search("that");*/

	LinkedList l1;

	for (int i = 1; i <= 4; ++i)
		l1.push(i);

	l1.recursiveReverse();

	getchar( );
	return 0;
}