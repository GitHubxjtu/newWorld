#pragma once
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class MyAToI
{
public:
	MyAToI();
	int removeElement(vector<int>& nums, int val) {
		int length = nums.size(), start = 0;
		while (start<length){
			if (nums[start] == val){
				length--;
				swap(nums[start], nums[length]);
			}
			else
				start++;
		}
		return length;
	}
	int myAtoi(string str) {
		long long ret = 0;
		int sign = 1;
		int pos = 0;
		pos = str.find_first_not_of(' ');
		if (pos<str.length() && str[pos] == '-'){
			pos++;
			sign = -1;
		}
		else if (pos<str.length() && str[pos] == '+'){
			pos++;
		}
		while (pos<str.length()){
			if (str[pos] - '0' >= 0 && str[pos] - '0' <= 9){
				ret *= 10;
				ret += (str[pos] - '0');
				pos++;
			}
			else
			{
				break;
			}
		}
		ret = ret*sign;
		if (ret >= INT_MAX)
			return INT_MAX;
		else if (ret <= INT_MIN)
			return INT_MIN;
		return ret;
	}
	~MyAToI();
};

