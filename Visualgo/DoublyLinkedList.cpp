#include "DoublyLinkedList.h"

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
