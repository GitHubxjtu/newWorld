#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class permute
{
public:
	permute();
	vector<vector<int>> permutev(vector<int>& nums) {
		vector<vector<int>> ans;
		if (nums.empty()) return ans;
		helper(ans, nums,0);
		return ans;
	}
	void helper(vector<vector<int>> &ans, vector<int> &nums, int k)
	{
		if (k == nums.size()){
			//string s;
			//for (int i = 0; i < k; i++){
			//	s += to_string(nums[i]);
			//}
		//	cout << s << endl;
			ans.push_back(nums);
			return;
		}
		for (int i = 0; i<nums.size() - k; i++)
		{
			swap(nums[k], nums[i + k]);
			helper(ans, nums, k + 1);
			swap(nums[k], nums[i + k]);
		}
	}
	string getPermutation(int n, int k) {
		string ret = "";
		if (n <= 0) return ret;
		vector<int> nums;
		for (int i = 1; i <= n; i++){
			nums.push_back(i);
		}
		for (int i = 0; i < n; i++){
			ret += to_string(nums[i]);
		}
		return ret;
	}
	void gethelp(vector<int> &nums, int k, int i){
	}
	~permute();
};

