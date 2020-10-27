#pragma once

//ื๎ะกีป
class MinStack
{
public:
	MinStack(int cap);
	~MinStack();

	void push(int val);
	int pop();
	int getMin();

	bool isEmpty();
private:
	MinStack();

	int* m_data;
	int* m_minData;

	int m_capacity;
	int m_size;
};

