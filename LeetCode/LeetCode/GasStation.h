#pragma once
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class GasStation
{
public:
	GasStation();
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int remain = 0, n = gas.size();
		vector<int> gascost(n,0);
		for (int i = 0; i < n; i++){
			gascost[i] = gas[i]-cost[i];
		}
		int j = 0;
		j = maxSubArrayID(gascost);
		remain = gas[j];
		for (int i = j; i<=j + n; i++)
		{
			remain -= cost[i%n];
			if (remain >= 0){
				remain += gas[(i+1)%n];
				if (i == j + n) return j;
			}
			else
			{
				break;
			}
		}
		return -1;
	}
	int maxSubArrayID(vector<int>& nums) {
		int n = nums.size();
		int ret = n - 1, temp = n - 1, tempp = n-1;
		int startMax = nums[n - 1];
		int allMax = nums[n - 1];
		int roundMax = INT_MIN, tempMax = 0, endMax = INT_MIN;
		for (int i = n - 2; i >= 0; i--)
		{
			if (nums[i]>startMax + nums[i]){
				startMax = nums[i];
			}
			else{
				startMax = startMax + nums[i];
			}
			if (startMax > allMax){
				allMax = startMax;
				ret = i;
			}
		}
		for (int i = 0; i<n; i++){
			tempMax += nums[i];
			if (roundMax<tempMax)
			{
				roundMax = tempMax;
				temp = i;
			}
		}		
		tempMax = 0;
		for (int i = n-1; i>temp; i--){
			tempMax += nums[i];
			if (endMax<tempMax)
			{
				endMax = tempMax;
				tempp = i;
			}
		}
		return roundMax+endMax>allMax ? tempp : ret;
	}
	~GasStation();
};

