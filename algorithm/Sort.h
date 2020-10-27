#pragma once
#include <vector>
#include <functional>

class Sort
{
public:
	//—°‘Ò≈≈–Ú
	static void sortBySelection(std::vector<int>& arr);
	//√∞≈›≈≈–Ú
	static void sortByBubble(std::vector<int>& arr);
	//≤Â»Î≈≈–Ú
	static void sortByInsertion(std::vector<int>& arr);
	
	//≤‚ ‘¥˙¬Î
	static void test(int testTimes = 500000);
private:

	static bool _test(std::function<void(std::vector<int>&)>, const char* name ,int testTimes, int maxSize = 20, int maxValue = 1000);
};

