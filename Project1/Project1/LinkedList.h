#pragma once

struct Node
{
	int data;
	Node *next;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void push(int key);
	void recursiveReverse();

private:
	void recursiveReverse(Node **node);
	Node *head;
};