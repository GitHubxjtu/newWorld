#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class MNmatrixSearch
{
public:
	MNmatrixSearch();
	bool searchMatrixII(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		int n = matrix.size();
		for (int i = 0; i<n; i++){
			if (binarySearch(matrix[i], target))
				return true;
		}
		return false;
	}
	bool binarySearch(vector<int> nums, int target){
		int l = 0, r = nums.size() - 1, mid = 0;
		while (l <= r){
			mid = (l + r) / 2;
			if (nums[mid] == target) return true;
			if (nums[mid]<target) l = mid + 1;
			else
				r = mid - 1;
		}
		return false;
	}
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		int n = matrix.size();
		int m = matrix[0].size();
		int l = 0, u = 0, r = m - 1, d = n - 1;
		int ll, uu, rr, dd;
		while (true){
			ll = l; uu = u; dd = d; rr = r;
		for (; u < d;){
				if (target > matrix[u][r])
					u++;
				else
					break;
			}
			for (; l < m;){
				if (target > matrix[d][l])
					l++;
				else
					break;
			}
			for (; d> u;){
				if (target < matrix[d][l]) d--;
				else
					break;
			}
			for (; r>l;){
				if (target < matrix[u][r]) r--;
				else
					break;
			}
			if (ll == l&&rr == r&&uu == u&&dd == d) break;
		}
			for (int i = l; i <= r; i++)
				if (target == matrix[d][i]) return true;
			for (int i = u; i < d; i++)
				if (target == matrix[i][r]) return true;
			return false;
	}
	~MNmatrixSearch();
};

