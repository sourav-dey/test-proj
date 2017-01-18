#pragma once

#ifndef __TRIE__
#define __TRIE__

#include <iostream>
#include <string>
#include <stack>
#define MAX_ALPHABETS 26

using namespace std;
struct TrieNode
{
	TrieNode *children[MAX_ALPHABETS];
	bool isLeaf;
};

class Trie
{
public:
	Trie();
	void getNode(TrieNode *&node);
	void insert(string word);
	bool search(string key);
	void deleteKey(string key);

private:
	TrieNode *root;
};
#endif // !__TRIE__

