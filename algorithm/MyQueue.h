#pragma once
#include <queue>
#include <stack>

//��������ʵ�ֵĶ���
class MyQueue
{
public:
	MyQueue(int cap);
	~MyQueue();
	void push(int val);
	int pop();
	bool isEmpty();

private:
	MyQueue();

	int getNextIndex(int baseIndex);

	int* m_data;
	int m_capacity;
	int m_size;

	int m_pushIndex;
	int m_popIndex;
};

//����ջʵ�ֵĶ���
class QueueByStack
{
public:
	void push(int val);
	int pop();
	bool isEmpty();
	void doPushToPop();
private:
	std::stack<int> m_pushStack;
	std::stack<int> m_popStack;
};

//���ڶ���ʵ�ֵ�ջ
class StackByQueue
{
public:
	void push(int val);
	int pop();
	bool isEmpty();
private:
	std::queue<int> m_que1;
	std::queue<int> m_que2;
};
