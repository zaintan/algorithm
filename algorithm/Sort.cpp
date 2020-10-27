#include "Sort.h"
#include "ZYUtil.h"

#include <algorithm>
#include <iostream>

using namespace std;

void Sort::sortBySelection(vector<int>& arr)
{
	if (arr.size() < 2)
		return;

	for (int i = 0; i < arr.size() - 1; i++)
	{
		int minIndex = i;
		for (int j = i+1; j < arr.size(); j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		if(i != minIndex)
			ZYUtil::swapVec(arr, i, minIndex);
	}
}

void Sort::sortByBubble(vector<int>& arr)
{
	if (arr.size() < 2)
		return;
	//0 - i-1
	//0 - i-2
	//0 - i-3
	for (int i = arr.size()-1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j+1])
				ZYUtil::swapVec(arr, j + 1, j);
		}

	}
}

void Sort::sortByInsertion(vector<int>& arr)
{
	if (arr.size() < 2)
		return;

	//0-0ÓÐÐò
	//0-iÏëÓÐÐò
	for (int i = 1; i < arr.size(); i++)
	{
		for(int j = i-1; j >= 0 && arr[j] > arr[j+1]; j--)
		{
			ZYUtil::swapVec(arr, j, j + 1);
		}

	}
}

void Sort::test(int testTimes)//testTimes = 500000
{
	_test(sortBySelection,"selection", testTimes);
	_test(sortByBubble, "bubble", testTimes);
	_test(sortByInsertion,"insertion", testTimes);
}


bool Sort::_test(function<void(vector<int>&)> sortFunc, const char* name, int testTimes, int maxSize, int maxValue)
{
	bool success = true;
	for (int i = 0; i < testTimes; i++)
	{
		vector<int> arr1 = ZYUtil::generateRandomVec(maxSize, maxValue);
		vector<int> arr2 = arr1;

		sortFunc(arr1);
		sort(arr2.begin(), arr2.end());

		if (!ZYUtil::isEqualVec(arr1, arr2))
		{
			success = false;
			cout <<"["<<name<< ",sort]" << endl;
			ZYUtil::printVec(arr1);
			ZYUtil::printVec(arr2);
			break;
		}
	}

	if (success) {
		cout << "[" << name << "] sort succeed!" << endl;
	}
	return success;
}
