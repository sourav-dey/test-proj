#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree()
{
	root = nullptr;
}

BinaryTree::~BinaryTree()
{
	destroyTree();
}

void BinaryTree::insert(int key)
{
	if (root == nullptr)
	{
		TreeNode *newNode = new TreeNode();
		newNode->data = key;
		newNode->left = nullptr;
		newNode->right = nullptr;
		newNode->parent = nullptr;
		root = newNode;
	}
	else
	{
		insert(key, root);
	}
}

void BinaryTree::destroyTree()
{
	destroySubTree(root);
}

void BinaryTree::printOutsideNodes()
{
	std::stack<TreeNode*> workingStack, rightStack;
	bool printLeafs = false;
	workingStack.push(root);
	
	TreeNode *node = workingStack.top();
	workingStack.pop();

	while (node != nullptr)
	{
		if (workingStack.empty() && printLeafs &&
			(node->left != nullptr || node->right != nullptr))
		{
			rightStack.push(node);
		}

		if (node->left == nullptr && node->right == nullptr)
		{
			printLeafs = true;
			std::cout << node->data << " ";
			node = workingStack.empty() ? nullptr : workingStack.top();
			if (node)
			{
				workingStack.pop();
			}
		}
		else
		{
			if (!printLeafs)
			{
				std::cout << node->data << " ";
			}

			if (node->left != nullptr && node->right != nullptr)
			{
				workingStack.push(node->right);
			}

			node = node->left ? node->left : node->right;
		}
	}

	while (!rightStack.empty())
	{
		cout << rightStack.top() << " ";
		rightStack.pop();
	}

}

TreeNode * BinaryTree::lowestCommonAncestor(TreeNode * l, TreeNode * r)
{
	TreeNode *lca = lowestCommonAncestor(root, l, r);
	return lca;
}

void BinaryTree::printInorderBT()
{
	cout << "Inorder Traversal: ";
	printInorderBT(root);
	cout << "\n";
}

void BinaryTree::printInorderBT(TreeNode *root)
{
	if (root == nullptr)
		return;
	printInorderBT(root->left);
	cout << root->data << " ";
	printInorderBT(root->right);
}



void BinaryTree::printPreorderBT()
{
	cout << "Preorder Traversal: ";
	printPreorderBT(root);
	cout << "\n";
}

void BinaryTree::printPreorderBT(TreeNode *root)
{
	if (root == nullptr)
		return;

	cout << root->data << " ";
	printInorderBT(root->left);
	printInorderBT(root->right);
}

void BinaryTree::printPostorderBT()
{
	cout << "Postorder Traversal: ";
	printPostorderBT(root);
	cout << "\n";
}

TreeNode * BinaryTree::lookUp(int key)
{
	TreeNode *node = lookUp(root, key);
	return node;
}

TreeNode * BinaryTree::lookUp(TreeNode * node, int key)
{
	if (node == nullptr)
	{
		return node;
	}

	if (key > node->data)
	{
		return lookUp(node->right, key);
	}
	else if (key < node->data)
	{
		return lookUp(node->left, key);
	}
	else
	{
		return node;
	}
}

TreeNode * BinaryTree::minValueNode()
{
	if (root == nullptr)
		return root;

	TreeNode *node = root;
	while (node->left)
	{
		node = node->left;
	}
	return node;
}

TreeNode * BinaryTree::maxValueNode()
{
	if (root == nullptr)
		return root;

	TreeNode *node = root;
	while (node->right)
	{
		node = node->right;
	}
	return node;
}

void BinaryTree::deleteKey(int key)
{
	// Search the node
	TreeNode *foundNode = lookUp(key);

	// Delete if the node is leaf node
	if (foundNode == nullptr)
		return;

	if (foundNode->left == nullptr && foundNode->right == nullptr)
	{
		foundNode->parent->left = nullptr;
		foundNode->parent->right = nullptr;

		delete foundNode;
		foundNode = nullptr;
	}
	//Delete if the node has only 2 children
	else if (foundNode->left != nullptr && foundNode->right != nullptr)
	{
		int foundMinValue = getMinValueAndDelete(foundNode);
		foundNode->data = foundMinValue;
	}
	//Delete if the node has only 1 child
	else
	{
		if (foundNode->left != nullptr)
		{
			foundNode->parent->left = foundNode->left;
			delete foundNode;
			foundNode = nullptr;
		}
		else if (foundNode->right != nullptr)
		{
			foundNode->parent->right = foundNode->right;
			delete foundNode;
			foundNode = nullptr;
		}
	}
}

void BinaryTree::printBFS()
{
	cout << "BFS: ";
	if (root == nullptr)
	{
		cout << "NULL";
		return;
	}

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		TreeNode *currentNode = q.front();
		q.pop();

		cout << currentNode->data << " ";
		if (currentNode->left != nullptr)
			q.push(currentNode->left);

		if (currentNode->right != nullptr)
			q.push(currentNode->right);
	}
	cout << "\n";
}

void BinaryTree::printDFS()
{
	cout << "DFS: ";
	if (root == nullptr)
	{
		cout << "NULL";
		return;
	}

	stack<TreeNode*> s;
	s.push(root);

	while (!s.empty())
	{
		TreeNode *currentNode = s.top();
		s.pop();

		cout << currentNode->data << " ";

		if (currentNode->right != nullptr)
			s.push(currentNode->right);

		if (currentNode->left != nullptr)
			s.push(currentNode->left);
	}
	cout << "\n";
}

bool BinaryTree::isBstInOrder()
{
	bool isBinarySearchTree = isBstInOrder(root);
	return isBinarySearchTree;
}

bool BinaryTree::isBstInOrder(TreeNode * node)
{
	static int min = INT_MIN;

	if (node != nullptr)
	{
		if (!isBstInOrder(node->left))
			return false;

		if (node->data > min)
		{
			min = node->data;
		}
		else
		{
			return false;
		}

		if (!isBstInOrder(node->right))
			return false;
	}
	return true;
}

bool BinaryTree::isBst()
{
	bool isBinarySearchTree = isBstUtil(root, INT_MIN, INT_MAX);
	return isBinarySearchTree;
}

bool BinaryTree::isBstUtil(TreeNode * node, int min, int max)
{
	if (node == nullptr)
		return true;

	if (node->data < min || node->data > max)
		return false;

	return isBstUtil(node->left, min, node->data - 1) &&
		isBstUtil(node->right, node->data + 1, max);
}



int BinaryTree::maxDepth()
{
	int maxD = maxDepth(root);
	return maxD;
}

int BinaryTree::maxDepth(TreeNode *node)
{
	if (node == nullptr || (node->left == nullptr && node->right == nullptr))
	{
		return 0;
	}

	int leftDepth = maxDepth(node->left);
	int rightDepth = maxDepth(node->right);

	if (leftDepth > rightDepth)
	{
		return leftDepth + 1;
	}
	else
	{
		return rightDepth + 1;
	}

}

int BinaryTree::minDepth()
{
	int minD = minDepth(root);
	return minD;
}

void BinaryTree::mirror()
{
	mirror(root);
}

bool BinaryTree::matchTree( TreeNode *node1, TreeNode *node2 )
{
	if (node1 == nullptr && node2 == nullptr)
	{
		return true;
	}
	if (node1 == nullptr || node2 == nullptr)
		return false;

	if (node1->data != node2->data)
		return false;
	
	return (matchTree(node1->left, node2->left) && matchTree(node1->right, node2->right));
}

bool BinaryTree::isSubTree(TreeNode * node1, TreeNode * node2)
{
	if (node2 == nullptr)
		return true;
	
	if (node1 == nullptr)
		return false;

	if (node1->data == node2->data)
		if (matchTree(node1, node2))
			return true;

	return isSubTree(node1->left, node2) || isSubTree(node1->right, node2);
}

void BinaryTree::mirror(TreeNode *node)
{
	if (node == nullptr)
	{
		return;
	}

	mirror(node->left);
	mirror(node->right);

	if (node->left && node->right)
	{
		TreeNode *tempNode = node->left;
		node->left = node->right;
		node->right = tempNode;
	}

}

int BinaryTree::minDepth(TreeNode *node)
{
	if (node == nullptr || (node->left == nullptr && node->right == nullptr))
	{
		return 0;
	}

	int leftDepth = minDepth(node->left);
	int rightDepth = minDepth(node->right);

	if (leftDepth < rightDepth)
		return leftDepth + 1;
	else
		return rightDepth + 1;
}

int BinaryTree::getMinValueAndDelete(TreeNode * node)
{
	TreeNode *currentNode = node;

	while (currentNode->left)
	{
		currentNode = currentNode->left;
	}
	int value = currentNode->data;
	currentNode->parent->left = nullptr;

	delete currentNode;
	currentNode = nullptr;
	return value;
}

void BinaryTree::printPostorderBT(TreeNode *root)
{
	if (root == nullptr)
		return;
	printPostorderBT(root->left);
	printPostorderBT(root->right);
	cout << root->data << " ";
}

TreeNode * BinaryTree::lowestCommonAncestor(TreeNode * root, TreeNode * l, TreeNode * r)
{
	if (root == nullptr || root == l || root == r)
		return root;

	TreeNode *left = lowestCommonAncestor(root->left, l, r);
	TreeNode *right = lowestCommonAncestor(root->right, l, r);

	if (left && right)
	{
		return root;
	}

	if (left == nullptr)
		return right;
	else
		return left;
}

void BinaryTree::insert(int key, TreeNode *leaf)
{
	if (key < leaf->data)
	{
		if (leaf->left != nullptr)
		{
			insert(key, leaf->left);
		}
		else
		{
			TreeNode *newNode = new TreeNode();
			newNode->data = key;
			newNode->left = nullptr;
			newNode->right = nullptr;
			newNode->parent = leaf;
			leaf->left = newNode;
		}
	}
	else if (key > leaf->data)
	{
		if (leaf->right != nullptr)
		{
			insert(key, leaf->right);
		}
		else
		{
			TreeNode *newNode = new TreeNode();
			newNode->data = key;
			newNode->left = nullptr;
			newNode->right = nullptr;
			newNode->parent = leaf;
			leaf->right = newNode;
		}
	}
}

void BinaryTree::destroySubTree(TreeNode * leaf)
{
	if (leaf != nullptr)
	{
		destroySubTree(leaf->left);
		destroySubTree(leaf->right);
		delete leaf;
		leaf = nullptr;
	}
}

