#pragma once
struct Node{
	int data = 0;
	Node* Next = nullptr;
	Node* Prev = nullptr;
};

struct doublyLinkedList
{
	Node* pHead = nullptr;
	Node* pTail = nullptr;

	void addTail(Node* node);

	void addHead(Node* node);

	void deleteTail();

	void deleteHead();
};

Node* create(int data);

