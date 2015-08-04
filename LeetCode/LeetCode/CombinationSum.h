#pragma once

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class CombinationSum
{
public:
	CombinationSum();
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(),candidates.end());
		vector<vector<int>> result;
		vector<int> res;
		helper(result,res,candidates,target,0);
		return result;
	}
	void helper(vector<vector<int>> &result, vector<int> &res, vector<int>& candidates, int target, int k){
		//int temp = target;
		if (target == 0){
			result.push_back(res);
			return;
		}
		else if (target < 0){ 
			return;
		}
		for (int i = k; i<candidates.size(); i++)
		{
			res.push_back(candidates[i]);		
			helper(result, res, candidates, target - candidates[i], i);
			res.pop_back();
			//target = temp;
		}
	}
	~CombinationSum();
};

