#include "DoublyLinkedList.h"
#include <iostream>

Node* create(int data)
{
	Node* node = nullptr;
	node = new Node;
	node->data = data;
	node->Next = nullptr;
	node->Prev = nullptr;
	return node;
}
void doublyLinkedList::addTail(Node* node)
{
	if (pHead == nullptr)
	{
		pHead = node; 
		pTail = node; 
	}
	else
	{
		pTail->Next = node;
		node->Prev = pTail;
		pTail = node;
	}
}

void doublyLinkedList::addHead(Node* node)
{
	if (pHead == nullptr)
	{
		pHead = node;
		pTail = node;
	}
	else
	{
		pHead->Prev = node;
		node->Next = pHead;
		pHead = node;
	}
}

void doublyLinkedList::deleteTail()
{
	if (pTail == nullptr) return;

	if (pHead == pTail)
	{
		delete pTail;
		pHead = nullptr;
		pTail = nullptr;
		return;
	}

	Node* temp = pTail->Prev;
	delete pTail;
	pTail = temp;
	pTail->Next = nullptr;
}

void doublyLinkedList::deleteHead()
{
	if (pHead == nullptr) return;

	if (pHead == pTail)
	{
		delete pHead;
		pHead = nullptr;
		pTail = nullptr;
		return;
	}

	Node* temp = pHead->Next;
	delete pHead;
	pHead = temp;
}

void doublyLinkedList::deleteIndexK(int k)
{
	int count = 0;

	if (k == 0) 
	{
		deleteHead();
		return;
	}

	Node* cur = pHead;
	while (cur != nullptr && count < k)
		cur = cur->Next, count++;

	if (cur == nullptr || cur->Next == nullptr)
	{
		deleteTail();
		return;
	}

	Node* prev = cur->Prev;
	Node* next = cur->Next;
	prev->Next = next;
	next->Prev = prev;
	delete cur;
}
void doublyLinkedList::insertIndexK(int k, int data)
{
	int count = 0;
	Node* cur = pHead;

	if (k <= 0)
	{
		addHead(create(data));
		return;
	}

	while (cur != nullptr && count < k)
	{
		cur = cur->Next;
		count++;
	}

	if (cur == nullptr)
	{
		addTail(create(data));
		return;
	}

	Node* temp = create(data);
	Node* prev = cur->Prev;

	temp->Prev = prev;
	temp->Next = cur;

	cur->Prev = temp;
	if (prev != nullptr)
	{
		prev->Next = temp;
	}
	else
	{
		pHead = temp;
	}
}

void doublyLinkedList::loadList()
{
	Node* cur = pHead;
	while (cur != nullptr)
	{
		std::cout << cur->data << " ";
		cur = cur->Next;
	}
}
