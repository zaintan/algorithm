#include "LinkedList.h"

#include <cassert>
#include <iostream>
#include <random>
//#include <time.h>
#include <sys/timeb.h>

using namespace std;

Node* LinkedList::reverse(Node* pHead)
{
	Node* pre = nullptr;
	while (pHead != nullptr)
	{
		Node* tmp = pHead->next;
		pHead->next = pre;
		pre = pHead;
		pHead = tmp;
	}
	return pre;
}

DoubleNode* LinkedList::reverse(DoubleNode* pHead)
{
	DoubleNode* pre = nullptr;
	while (pHead != nullptr) 
	{
		DoubleNode* tmp = pHead->next;
		pHead->next = pre;
		pHead->pre = tmp;
		pre = pHead;
		pHead = tmp;
	}
    return pre;
}

Node* LinkedList::remove(Node* pHead, int value)
{
	//去掉连续头
	while (pHead != nullptr && pHead->data == value) 
	{
		Node* tmp = pHead->next;
		delete pHead;
		pHead = tmp;
	}
	if (pHead == nullptr)
		return nullptr;

	Node* cur = pHead;
	Node* pre = nullptr;
	while (cur != nullptr) 
	{
		if (cur->data == value) 
		{
			pre->next = cur->next;
			delete cur;
			cur = pre->next;
		}
		else 
		{
			pre = cur;
			cur = cur->next;
		}
		
	}
    return pHead;
}

DoubleNode* LinkedList::remove(DoubleNode* pHead, int value)
{
	while (pHead != nullptr && pHead->data == value) 
	{
		 DoubleNode* next = pHead->next;
		 next->pre = nullptr;
		 delete pHead;
		 pHead = next;
	}
	DoubleNode* cur = pHead;
	DoubleNode* pre = nullptr;
	while (cur != nullptr)
	{
		if (cur->data == value)
		{
			pre->next = cur->next;
			if (pre->next != nullptr)
				pre->next->pre = pre;
			delete cur;
			cur = pre->next;
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
    return pHead;
}

Node* generateRandomNode() {
	struct _timeb ts;
	_ftime64_s(&ts);
	srand((unsigned)ts.millitm);

	int maxArr   = 10;
	int maxValue = 1000;
	int cap = rand() % maxArr + 1;

	Node* pHead = nullptr;
	Node* cur = nullptr;

	for (int i = 0; i < cap; i++)
	{
		Node* p = new Node(rand() % maxValue);
		if (cur) {
			cur->next = p;
			cur = p;
		}
		else {
			pHead = p;
			cur = p;
		}
	}
	return pHead;
}

DoubleNode* generateRandomDoubleNode() {
	

	int maxArr = 10;
	int maxValue = 1000;
	int cap = rand() % maxArr + 1;

	DoubleNode* pHead = nullptr;
	DoubleNode* cur = nullptr;

	for (int i = 0; i < cap; i++)
	{
		DoubleNode* p = new DoubleNode(rand() % maxValue);
		if (cur) {
			cur->next = p;
			p->pre = cur;
			cur = p;
		}
		else {
			pHead = p;
			cur = p;
		}
	}
	return pHead;
}

bool isEqual(Node* p1, Node* p2)
{
	while (p1 != nullptr || p2 != nullptr)//只要不同时为nullptr
	{
		if (p1 == nullptr || p2 == nullptr)//只有一个为nullptr
			return false;

		if (p1->data != p2->data)
			return false;
		p1 = p1->next;
		p2 = p2->next;
	}
	return true;
}

bool isEqual(DoubleNode* p1, DoubleNode* p2)
{
	while (p1 != nullptr || p2 != nullptr)//只要不同时为nullptr
	{
		if (p1 == nullptr || p2 == nullptr)//只有一个为nullptr
			return false;

		if (p1->data != p2->data)
			return false;
		p1 = p1->next;
		p2 = p2->next;
	}
	return true;
}

void print(DoubleNode* p)
{
	if (p == nullptr)
		cout << "[]" << endl;

	cout << "[";
	while (p != nullptr)
	{
		cout << p->data;
		p = p->next;
		if (p != nullptr)
			cout << "<=>";
	}
	cout << "]" << endl;
}

void print(Node* p)
{
	if (p == nullptr)
		cout << "[]" << endl;

	cout << "[";
	while (p != nullptr)
	{
		cout << p->data;
		p = p->next;
		if (p != nullptr)
			cout << "->";
	}
	cout << "]" << endl;
}

void clear(Node* p)
{
	while (p != nullptr)
	{
		Node* tmp = p->next;
		delete p;
		p = tmp;
	}
}

void clear(DoubleNode* p)
{
	while (p != nullptr)
	{
		DoubleNode* tmp = p->next;
		delete p;
		p = tmp;
	}
}
void LinkedList::test()
{
	//srand((unsigned)time(NULL));
	//
	cout << "test reverse node:"<<endl;
	for (int i = 0; i < 10; i++)
	{
		Node* pHead = generateRandomNode();
		print(pHead);
		Node* rNode = reverse(pHead);
		print(rNode);
		clear(rNode);
		cout << endl;
	}

	cout << "test reverse doubleNode:" << endl;
	for (int i = 0; i < 10; i++)
	{
		DoubleNode* pHead = generateRandomDoubleNode();
		print(pHead);
		DoubleNode* rNode = reverse(pHead);
		print(rNode);
		clear(rNode);
		cout << endl;
	}
}

