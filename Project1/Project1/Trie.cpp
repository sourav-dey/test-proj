#include "Trie.h"

Trie::Trie()
{
	root = new TrieNode();
	getNode(root);
}

void Trie::getNode(TrieNode *&node)
{
	if (node)
	{
		for (int i = 0; i < MAX_ALPHABETS; ++i)
		{
			node->children[i] = nullptr;
		}

		node->isLeaf = false;
	}
}

void Trie::insert(string word)
{
	int length = word.length();
	TrieNode *currentNode = root;

	for (int i = 0; i < length; ++i)
	{
		int index = word[i] - 'a';
		if (currentNode->children[index] == nullptr)
		{
			TrieNode *newNode = new TrieNode();
			getNode(newNode);
			currentNode->children[index] = newNode;
		}
		currentNode = currentNode->children[index];
	}
	currentNode->isLeaf = true;
}

bool Trie::search(string key)
{
	int length = key.length();
	TrieNode *currentnode = root;

	for (int i = 0; i < length; ++i)
	{
		int index = key[i] - 'a';
		if (!currentnode->children[index])
		{
			return false;
		}
		currentnode = currentnode->children[index];
	}
	return currentnode!= nullptr && currentnode->isLeaf;
}

void Trie::deleteKey(string key)
{
	int length = key.length();
	TrieNode *currentNode = root;

	stack<TrieNode*> sNodes;

	for (int i = 0; i < length; ++i)
	{
		int index = key[i] - 'a';
		if (!currentNode->children[index])
			return;

		sNodes.push(currentNode);
		currentNode = currentNode->children[index];
	}

	if (currentNode != nullptr && currentNode->isLeaf)
	{
		TrieNode *tNode = sNodes.top();
		sNodes.pop();
		delete tNode;
		tNode = nullptr;
	}
}
