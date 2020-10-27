#include "MinStack.h"
#include <iostream>

MinStack::MinStack(int cap)
{
	m_capacity = cap;
	m_data = new int[cap];
	m_minData = new int[cap];
	m_size = 0;
}

MinStack::~MinStack()
{
	if (m_data != nullptr)
		delete []m_data;

	if (m_minData != nullptr)
		delete []m_minData;
}

void MinStack::push(int val)
{
	if (m_size == m_capacity) {
		std::cout << "push error! stack is full!" << std::endl;
		return;
	}
	
	m_data[m_size] = val;
	if (m_size == 0)
		m_minData[m_size] = val;
	else
		m_minData[m_size] = m_minData[m_size - 1] < val ? m_minData[m_size - 1] : val;//math.min();
	m_size++;
}

int MinStack::pop()
{
	if (isEmpty()) {
		std::cout << "pop error! stack is empty!" << std::endl;
		return -1;
	}
	return m_data[m_size--];
}

int MinStack::getMin()
{
	if (m_size == 0) {
		std::cout << "getMin error! stack is empty!" << std::endl;
		return -1;
	}
	return m_minData[m_size-1];
}

bool MinStack::isEmpty()
{
	return m_size == 0;
}
