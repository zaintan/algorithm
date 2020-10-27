#include "MyQueue.h"
#include<iostream>

MyQueue::MyQueue(int cap)
{
	m_capacity = cap;
	m_data = new int[cap];
	m_pushIndex = -1;
	m_popIndex = -1;
	m_size = 0;
}

MyQueue::~MyQueue()
{
	if (m_data != nullptr)
		delete m_data;
	m_data = nullptr;
}

void MyQueue::push(int val)
{
	if (m_size == m_capacity) {
		std::cout << "push error! queue is full!" << std::endl;
		return;
	}

	m_pushIndex = getNextIndex(m_pushIndex);
	m_data[m_pushIndex] = val;
	m_size++;
}

int MyQueue::pop()
{
	if (isEmpty()) {
		std::cout << "pop error! queue is empty!" << std::endl;
		return -1;
	}
	m_size--;
	m_popIndex = getNextIndex(m_popIndex);
	return m_data[m_popIndex];
}

bool MyQueue::isEmpty()
{
	return m_size == 0;
}

int MyQueue::getNextIndex(int baseIndex)
{
	return baseIndex == m_capacity-1 ? 0 :baseIndex+1;
}



void QueueByStack::push(int val)
{
	m_pushStack.push(val);
	doPushToPop();
}

int QueueByStack::pop()
{
	if (isEmpty()) {
		std::cout << "pop error! queue is empty!" << std::endl;
		return -1;
	}

	doPushToPop();
	int val = m_popStack.top();
	m_popStack.pop();
	return val;
}

bool QueueByStack::isEmpty()
{
	return m_popStack.empty() && m_pushStack.empty();
}

void QueueByStack::doPushToPop()
{
	if (m_popStack.empty()) {//
		while (!m_pushStack.empty())
		{
			m_popStack.push(m_pushStack.top());
			m_pushStack.pop();
		}
	}
}

void StackByQueue::push(int val)
{
	if (m_que1.empty())
		m_que2.push(val);
	else
		m_que1.push(val);
}

int StackByQueue::pop()
{
	if (isEmpty()) {
		std::cout << "pop error! stack is empty!" << std::endl;
		return -1;
	}
	std::queue<int>& from = m_que1.empty() ? m_que2 : m_que1;
	std::queue<int>& to   = m_que1.empty() ? m_que1 : m_que2;
	while (from.size() > 1) {
		to.push(from.front());
		from.pop();
	}	
	int ret = from.front();
	from.pop();
	return ret;
}

bool StackByQueue::isEmpty()
{
	return 	m_que1.empty() && m_que2.empty();
}
