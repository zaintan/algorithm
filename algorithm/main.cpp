#include<iostream>
#include "Sort.h"

#include "LinkedList.h"

#include "MyQueue.h"

using namespace std;

int main() {

	//Sort::test();
	//LinkedList::test();

	cout << "MyQueue test:" << endl;
	MyQueue que(5);
	que.push(1);
	que.push(2);
	que.push(3);
	que.push(4);
	que.push(5);
	cout << que.pop() << endl;
	cout << que.pop() << endl;
	cout << que.pop() << endl;
	que.push(10);
	que.push(20);
	que.push(30);
	cout << que.pop() << endl;
	cout << que.pop() << endl;
	cout << que.pop() << endl;
	cout << que.pop() << endl;
	cout << que.pop() << endl;

	/// <summary>
	/// 
	cout << "StackByQueue test:" << endl;
	StackByQueue s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
	/// </summary>
	/// <returns></returns>
	cout << "QueueByStack test:" << endl;
	QueueByStack q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	cout << q1.pop() << endl;
	cout << q1.pop() << endl;
	cout << q1.pop() << endl;
	cout << q1.pop() << endl;
	return 0;
}