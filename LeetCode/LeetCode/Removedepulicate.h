#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Removedepulicate
{
public:
	Removedepulicate();
	int removeDuplicates(vector<int>& nums) {
		vector<int> temp;
		if (nums.empty())return 0;
		int length = 0, count = 1;
		temp.push_back(nums[0]);
		for (int i = 0; i<nums.size() - 1; i++)
		{
			if (nums[i + 1]>nums[i])
			{
				length += count;
				temp.push_back(nums[i + 1]);
				count = 1;
			}
			else{
				if (count < 2){
					temp.push_back(nums[i+1]);
					count++;
				}
			}
		}
		length += count;
		nums = temp;
		return length;
	}
	~Removedepulicate();
};

