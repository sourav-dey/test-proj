#pragma once

#ifndef __BINARY_TREE__
#define __BINARY_TREE__

#include <stack>
#include <iostream>
#include <queue>

struct TreeNode
{
	int data;
	TreeNode *right;
	TreeNode *left;
	TreeNode *parent;
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void insert(int key);
	void destroyTree();
	void printOutsideNodes();
	TreeNode *lowestCommonAncestor(TreeNode * l, TreeNode *r);
	void printInorderBT();
	void printPreorderBT();
	void printPostorderBT();
	TreeNode *lookUp(int key);
	TreeNode *minValueNode();
	TreeNode *maxValueNode();
	void deleteKey(int key);
	void printBFS();
	void printDFS();
	bool isBstInOrder();
	bool isBst();
	int maxDepth();
	int minDepth();
	void mirror();
	bool matchTree(TreeNode *node1, TreeNode *node2);
	bool isSubTree(TreeNode *node1, TreeNode *node2);

private:
	void insert(int key, TreeNode *leaf);
	void destroySubTree(TreeNode *leaf);
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *l, TreeNode *r);
	void printInorderBT(TreeNode *root);
	void printPreorderBT(TreeNode *root);
	void printPostorderBT(TreeNode *root);
	TreeNode *lookUp(TreeNode *node, int key);
	int getMinValueAndDelete(TreeNode *node);
	bool isBstInOrder(TreeNode *node);
	bool isBstUtil(TreeNode *node, int min, int max);
	int maxDepth(TreeNode *node);
	int minDepth(TreeNode *node);
	void mirror(TreeNode *node);


	TreeNode *root;
};
#endif
