#pragma once

#include <vector>
class ZYUtil
{
public:
	//����vec �±�i,j����λ�õ�ֵ
	static void swapVec(std::vector<int>& arr, int i, int j);
	//�������vec
	static std::vector<int> generateRandomVec(int maxSize, int maxValue);
	//�ж�����vec�Ƿ����
	static bool isEqualVec(std::vector<int>& arr1, std::vector<int>& arr2);
	//��ӡvec
	static void printVec(std::vector<int>& arr1);
};

