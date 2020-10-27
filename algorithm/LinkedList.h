#pragma once
struct Node
{
	int data;
	Node* next;

	Node(int d) {
		data = d;
		next = nullptr;
	}
};

struct DoubleNode
{
	int data;
	DoubleNode* next;
	DoubleNode* pre;

	DoubleNode(int d) {
		data = d;
		next = nullptr;
		pre = nullptr;
	}
};


class LinkedList {
public:
	static Node* reverse(Node* pHead);
	static DoubleNode* reverse(DoubleNode* pHead);

	static Node* remove(Node* pHead, int value);
	static DoubleNode* remove(DoubleNode* pHead, int value);

	static void test();
};

