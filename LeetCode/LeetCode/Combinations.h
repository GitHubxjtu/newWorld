#pragma once
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Combinations
{
public:
	Combinations(); 
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> res;
		helper(result, res, 1, n, k);
		return result;
	}
	void helper(vector<vector<int> > &ans, vector<int> &temp, int s, int n, int k){
		if (0 == k){
			ans.push_back(temp);
			return;
		}
		for (int i = s; i <= n - k + 1; i++){
			temp.push_back(i);
			helper(ans, temp, i + 1, n, k - 1);
			temp.pop_back();
		}
	}
	virtual ~Combinations();
};

