#pragma once
 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class KthSmallestElementInBST
{
public:
	KthSmallestElementInBST();
	int kthSmallest(TreeNode* root, int k) {
		if (nodeCount(root->left) +1 > k) return kthSmallest(root->left, k);
		if (nodeCount(root->left) + 1 < k) {
			return kthSmallest(root->right, k - nodeCount(root->left)-1);
		}
		if (nodeCount(root->left)+1==k) return root->val;
	}
	int nodeCount(TreeNode *root){
		if (!root) return 0;
		return nodeCount(root->left) + nodeCount(root->right) + 1;
	}
	~KthSmallestElementInBST();
};

