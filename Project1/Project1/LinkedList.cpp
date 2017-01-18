#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::~LinkedList()
{
	Node *current = head;

	while (current)
	{
		Node *prev = current;
		current = current->next;
		delete prev;
	}
}

void LinkedList::push(int key)
{
	Node *newNode = new Node();
	newNode->data = key;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		Node *current = head;
		while (current->next)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

void LinkedList::recursiveReverse()
{
	recursiveReverse(&head);
}

void LinkedList::recursiveReverse(Node **node)
{
	if (*node == nullptr)
		return;

	Node *first = *node;
	Node *rest = first->next;

	if (rest == nullptr)
		return;

	recursiveReverse(&rest);
	first->next->next = first;
	first->next = nullptr;

	*node = rest;
}
