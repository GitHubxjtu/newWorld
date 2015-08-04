#pragma once
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class CombinationSum3
{
public:
	CombinationSum3();
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> result;
		if (n>45) return result;
		vector<int> res;
		getCombinationSum3(result, res, k, n, 1);
		return result;
	}
	void getCombinationSum3(vector<vector<int>>& ans, vector<int> &res, int k, int n, int s){
		if (k == 0 && n == 0){
			ans.push_back(res);
			return;
		}
		for (int i = s; k >= 0 && 0<i&&i<10; i++){
			if (n - s<0) return;
			res.push_back(i);
			getCombinationSum3(ans, res, k - 1, n - i, i + 1);
			res.pop_back();	


		}
	}
	~CombinationSum3();
};

