#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;
class SearchRotated
{
public:
	SearchRotated();
	int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size()-1, mid = 0;
		while (l<=r){
			mid = (l + r) / 2;
			if (target == nums[mid]) return mid;
			if (nums[l]<=nums[mid]){
				if (nums[l]  <=target&&target<nums[mid]) 
					r = mid-1;
				else 
					l = mid + 1;
			}
			else{
				if (nums[mid]<target&&target <= nums[r]) 
					l = mid + 1;
				else
					r = mid-1;
			}
		}
		return -1;
	}
	virtual ~SearchRotated();
};

