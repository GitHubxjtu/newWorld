#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
class BiggesrNumber
{
public:
	BiggesrNumber();
	bool bigger(int a, int b){
		int k = a, p = b;
		if (a == 0|| a == b) return false;
		if (b == 0 ) return true;
		vector<int> c, d;
		if (a < 10){
			while (b){
				d.push_back(b % 10);
				b = b / 10;
			}
			reverse(d.begin(), d.end());
			for (int i = 0; i < d.size(); i++)
			{
				if (a>d[i]) return true;
				if (a < d[i]) return false;
			}
			return false;
		}
		if (b < 10) return !bigger(b, a);
		while (a){
			c.push_back(a % 10);
			a = a / 10;
		}
		while (b){
			d.push_back(b % 10);
			b = b / 10;
		}
		reverse(c.begin(), c.end());
		reverse(d.begin(), d.end());
		int pos = 0;
		while (pos < c.size() && pos < d.size()){
			if (c[pos]>d[pos])  return true;
			else if (c[pos] < d[pos]) return false;
			pos++;
		}
		return c.size() < d.size()?bigger(k,d[pos]):bigger(c[pos],p);
	}
	string largestNumber(vector<int> &nums){
		vector<string> strs;
		for (int i = 0; i < nums.size();i++)
		{
			strs.push_back(to_string(nums[i]));
		}
		sort(strs.begin(), strs.end(), [](string &s1, string &s2){return s1 + s2 > s2 + s1; });

		ostringstream s;
		if (strs[0] == "0") return "0";
		for (int i = 0; i < strs.size(); i++){
			s << strs[i];
		}
		return s.str();
	}
	string largestNumberII(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++){
			for (int j = nums.size() - 1; j > i; j--){
				if (bigger(nums[j], nums[j-1]))
				{
					swap(nums[j-1],nums[j]);
				}				
			}
		}
		ostringstream s;
		if (nums[0] == 0) return "0";
		for (int i = 0; i < nums.size(); i++){
			s << nums[i];
		}
		return s.str();
	}
	~BiggesrNumber();
};

