#include "ZYUtil.h"


#include <cassert>
#include <iostream>
#include <random>
#include <string>
#include <time.h>

using namespace std;

void ZYUtil::swapVec(std::vector<int>& arr, int i, int j)
{
	if (i == j)
		return;
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

std::vector<int> ZYUtil::generateRandomVec(int maxSize, int maxValue)
{
	assert(maxSize > 0 && maxValue > 0);

	srand((unsigned)time(NULL));

	int cap = rand() % maxSize;
	vector<int> ret;//cap

	for (int i = 0; i < cap; i++)
	{
		ret.push_back(rand() % maxValue);
	}
	//math.random
	return ret;
}

bool ZYUtil::isEqualVec(std::vector<int>& arr1, std::vector<int>& arr2)
{
	if (arr1.size() != arr2.size())
		return false;

	for (int i = 0; i < arr1.size(); i++)
	{
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}

void ZYUtil::printVec(std::vector<int>& arr)
{
	cout << "[";
	for (int i = 0; i < arr.size(); i++)
	{
		if (i != arr.size() - 1)
			cout << arr[i] << ",";
		else
			cout << arr[i];
	}
	cout << "]" << endl;
}
