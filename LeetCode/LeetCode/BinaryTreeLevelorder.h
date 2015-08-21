#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class BinaryTreeLevelorder
{
public:
	BinaryTreeLevelorder();
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (!root) return ans;
		vector<int> temp;
		TreeNode *pNode = root;
		queue<TreeNode *> q;
		q.push(pNode);
		while (!q.empty()){
			int size = q.size();
			for (int i = 0; i < size; i++){
				pNode = q.front();
				temp.push_back(pNode->val);
				q.pop();
				if (pNode->left)
					q.push(pNode->left);
				if (pNode->right)
					q.push(pNode->right);
			}
			ans.push_back(temp);
			temp.clear();
		}
		return ans;
	}
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;
		if (!root) return ans;
		int level = maxDepth(root);
		levelHelper(ans, root, level);
		return ans;
	}
	void levelHelper(vector<vector<int>> &ans, TreeNode *root, int level)
	{
		if (!root || level<=0) return;
		while (ans.size() < level){
			ans.push_back(vector<int>());
		}
		ans[level-1].push_back(root->val);
		levelHelper(ans, root->left, level - 1);
		levelHelper(ans, root->right, level - 1);
	}
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;
		int a = maxDepth(root->right) + 1;
		int b = maxDepth(root->left) + 1;
		return a>b ? a : b;
	}
	~BinaryTreeLevelorder();
};

