#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class SingleOne
{
public:
	SingleOne();
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for (int i = 0; i<nums.size(); i++)
		{
			ret ^= nums[i];
		}
		return ret;
	}
	int singleNumberII(vector<int>& nums) {//three <-> only one
		int ones = 0, twos = 0;
		for (int i = 0; i<nums.size(); i++)
		{
			ones = (ones^nums[i])&~twos;
			twos = (twos^nums[i])&~ones;
		}
		return ones;
	}
	int singleNumberIII(vector<int>& nums) {//three <-> only one
		int result = 0;
		for (int i = 0; i<32; i++)
		{
			int x = 1 << i;
			int sums = 0;
			for (int j = 0; j < nums.size(); j++){
				if (x&nums[j])
				{
					sums++;
				}
			}
			if (sums % 3){
				result |= x;
			}
		}
		return result;
	}
	int singleNumberIV(vector<int>& nums) {//five <-> only one
		int  ones=0, twos=0, threes=0;
		for (int j = 0; j < nums.size(); j++){
			ones = (ones^nums[j])&~threes;
			twos = (twos);
			threes = nums[j] & ones&twos;
		}
		return ones;
	}
	~SingleOne();
};

