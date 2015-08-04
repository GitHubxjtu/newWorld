#pragma once
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class MinSubArrayLength
{
public:
	MinSubArrayLength();    
	int minSubArrayLen(int s, vector<int>& nums) {
		int l = 0;
		int r = 0;
		int n = nums.size() - 1;
		int ans = n + 2;
		int sum = 0;
		while (r <= n){
			while (sum<s){
				sum += nums[r];
				r++;
			}
			if (l<r){
				ans = min(ans, r - l+1);
				if (sum<s&&r>n) break;
				sum -= nums[l];
				l++;
			}
		}
		while(l<r){
			ans = min(ans, r - l + 1);
			if (sum<s&&r>n) break;
			sum -= nums[l];
			l++;
		}
		return ans == n + 2 ? 0 : ans;
	}
	int minSubArrayLen2(int s, vector<int>& nums) {
		if (nums.empty()) return 0;
		int sum = 0;
		int l = 0, r = nums.size() - 1;
		for (int i = 0; i <= r; i++) sum += nums[i];
		if (s>sum) return 0;
		int ans = 0;
		helper(ans, s, nums, l, r);
		return ans;

	}
	int helper(int &ans, int s, vector<int>& nums, int l, int r){
		int mid; int i = l, j = r;
		mid = nums[(l + r) / 2];
		while (i <= j){
			while (nums[i] < mid)   i++;
			while (nums[j] > mid)   j--;
			if (i <= j)
			{
				swap(nums[i], nums[j]);
				i++; j--;
			}
		}
		int sum = 0;
		for (int k = i; k <= r; k++) 
			sum += nums[k];
		if (s - sum == 0) { ans += r - i + 1; return ans; }
		if (s - sum > 0){ 
			if (i > r) return ++ans;
			ans += r - i + 1; 
			helper(ans, s-sum, nums, l, i - 1);
		}
		if (s - sum < 0){
			if (r == i)
			{
				ans++;
				return ans;
			}
			helper(ans, s, nums, i, r);
		}
	}
	virtual ~MinSubArrayLength();
};

