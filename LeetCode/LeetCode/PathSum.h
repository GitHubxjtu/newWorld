#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
struct TreeNode {
int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class PathSum
{
public:
	PathSum();   
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ret;
		if (!root) return ret;
		vector<int> temp;
		helper(root, sum, ret, temp);
		return ret;

	}
	void helper(TreeNode* root, int sum, vector<vector<int>> &ans, vector<int> &temp)
	{
		if (root == NULL){
			return;
		}
		if (sum == root->val && root->left == NULL&&root->right == NULL)
		{
			temp.push_back(root->val);
			ans.push_back(temp);
			temp.pop_back();
			return;
		}
		temp.push_back(root->val);
		helper(root->left, sum - root->val, ans, temp);
		helper(root->right, sum - root->val, ans, temp);
		temp.pop_back();
	}
	virtual ~PathSum();
};

