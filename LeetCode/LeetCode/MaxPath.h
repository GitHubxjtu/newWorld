#pragma once
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class MaxPath
{
public:
	MaxPath();
	int maxPathSum(TreeNode* root){
		if (!root) return 0;
		int ret = root->val + maxRoottoLeef(root->left) + maxRoottoLeef(root->right);
		return max(ret,max(maxPathSum(root->left),maxPathSum(root->right)));
	}
	int maxRoottoLeef(TreeNode* root)
	{
		if (!root) return 0;
		if (root && (!root->left) && (root->right)) return root->val;
		return root->val + max(maxRoottoLeef(root->left),maxRoottoLeef(root->right));
	}
	~MaxPath();
};

