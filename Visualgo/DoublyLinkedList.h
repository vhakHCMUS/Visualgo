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

	void insertIndexK(int k, int data);

	void deleteTail();

	void deleteHead();

	void deleteIndexK(int k);
};

Node* create(int data);

