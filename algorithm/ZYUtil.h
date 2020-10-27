#pragma once

#include <vector>
class ZYUtil
{
public:
	//交换vec 下标i,j所在位置的值
	static void swapVec(std::vector<int>& arr, int i, int j);
	//生成随机vec
	static std::vector<int> generateRandomVec(int maxSize, int maxValue);
	//判断两个vec是否相等
	static bool isEqualVec(std::vector<int>& arr1, std::vector<int>& arr2);
	//打印vec
	static void printVec(std::vector<int>& arr1);
};

