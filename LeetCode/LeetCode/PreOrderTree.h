#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	
	TreeNode *right;

	TreeNode(int x):val(x),left(NULL),right(NULL){}

};
class PreOrderTree
{
public:
	PreOrderTree();
	vector<int> recurPreorder(TreeNode* root)
	{
		vector<int> ans;
		if (!root) return ans;
		recurPreHelper(ans,root);
		return ans;
		
	}
	void recurPreHelper(vector<int> &ans,TreeNode *root)
	{
		if (!root) return;
		ans.push_back(root->val);
		recurPreHelper(ans,root->left);
		recurPreHelper(ans,root->right);
	}
	vector<int> recurInorder(TreeNode* root)
	{
		vector<int> ans;
		if (!root) return ans;
		recurInHelper(ans, root);
		return ans;

	}
	void recurInHelper(vector<int> &ans, TreeNode *root)
	{
		if (!root) return;
		recurInHelper(ans, root->left);
		ans.push_back(root->val);
		recurInHelper(ans, root->right);
	}
	vector<int> recurPostorder(TreeNode* root)
	{
		vector<int> ans;
		if (!root) return ans;
		recurPostHelper(ans, root);
		return ans;

	}
	void recurPostHelper(vector<int> &ans, TreeNode *root)
	{
		if (!root) return;
		recurPostHelper(ans, root->left);
		recurPostHelper(ans, root->right);
		ans.push_back(root->val);
	}
	vector<int> preorderTraversalII(TreeNode* root) {
		TreeNode *pNode = root;
		vector<int> ans;
		stack<TreeNode *> s;
		if (root)
		 s.push(pNode);
		while (!s.empty()){
			pNode = s.top();
			ans.push_back(pNode->val);
			s.pop();
			if (pNode->right)
				s.push(pNode->right);
			if (pNode->left)
				s.push(pNode->left);
		}
		return ans;
	}
	vector<int> inorderTraversal(TreeNode* root){
		TreeNode *cur = root, *prev = NULL;
		vector<int> ans;
		while (cur)
		{
			if (cur->left == NULL)          // 1.
			{
				ans.push_back(cur->val);
				cur = cur->right;
			}
			else
			{
				prev = cur->left;
				while (prev->right&&prev->right != cur){
					prev = prev->right;
				}
				if (prev->right == NULL)
				{
					prev->right = cur;
					cur = cur->left;
				}
				else
				{
					prev->right = NULL;
					ans.push_back(cur->val);
					cur = cur->right;
				}
			}
		}
		return ans;
	}
	vector<int> preorderTraversal(TreeNode* root){
		TreeNode *cur = root, *prev = NULL;
		vector<int> ans;
		while (cur)
		{
			if (cur->left == NULL)          // 1.
			{
				ans.push_back(cur->val);
				cur = cur->right;
			}
			else
			{
				prev = cur->left;
				while (prev->right&&prev->right != cur){
					prev = prev->right;
				}
				if (prev->right == NULL)
				{
					prev->right = cur;
					ans.push_back(cur->val);
					cur = cur->left;
				}
				else
				{
					prev->right = NULL;
					cur = cur->right;
				}
			}
		}
		return ans;
	}	
	vector<int> postorderTraversalII(TreeNode* root){
		vector<int> ans;
		if (!root) return ans;
		TreeNode dump(0);
		dump.left = root;
		TreeNode *cur = &dump, *prev = NULL;
		while (cur)
		{
			if (cur->left == NULL)          // 1.
			{
				cur = cur->right;
			}
			else
			{
				prev = cur->left;
				while (prev->right&&prev->right != cur){
					prev = prev->right;
				}
				if (prev->right == NULL)
				{
					prev->right = cur;
					cur = cur->left;
				}
				else
				{
					prev->right = NULL;
					pushToVector(ans,cur->left,prev);
					cur = cur->right;
				}
			}
		}
		return ans;
	}
	 void reverse(TreeNode *from, TreeNode *to) // reverse the tree nodes 'from' -> 'to'.
		 {
		     if (from == to)
			         return;
		     TreeNode *x = from, *y = from->right, *z;
		     while (true)
			     {
			         z = y->right;
			         y->right = x;
			         x = y;
			         y = z;
			         if (x == to)
				             break;
			     }
		 }
	 void pushToVector(vector<int> &ans, TreeNode *from, TreeNode *to)
	 {
		 reverse(from, to);
		 
			     TreeNode *p = to;
		      while (true)
			      {
			          ans.push_back( p->val);
			          if (p == from)
				             break;
			          p = p->right;
			      }
		 
			      reverse(to, from);
	 }
	vector<int> inorderTraversalII(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> ret;
		TreeNode *pNode = root;
		if (!root) return ret;
		while (pNode)
		{
			s.push(pNode);
			pNode = pNode->left;
		}
		while (!s.empty()){
			pNode = s.top();
			s.pop();
			ret.push_back(pNode->val);
			if (pNode->right){
				pNode = pNode->right;
				while (pNode)
				{
					s.push(pNode);
					pNode = pNode->left;
				}
			}
		}
		return ret;
	}

	vector<int> postOrderTraversal(TreeNode* root) {
		TreeNode *cur;
		TreeNode *pre = NULL;
		stack<TreeNode*> s;
		vector<int> ret;
		if (root)
		   s.push(root);
		while (!s.empty())
		{
			cur = s.top();
			if (cur->left == NULL&&cur->right == NULL || pre && (pre == cur->left || pre == cur->right)){
				ret.push_back(cur->val);
				s.pop();
				pre = cur;
			}
			else
			{
				if (cur->right)
					s.push(cur->right);
				if (cur->left)
					s.push(cur->left);
			}
		}
		return ret;
	}
	struct TreeNd{
		TreeNode *node;
		bool isFirst;
		TreeNd(TreeNode *n) :node(n), isFirst(true){}
		TreeNd TreeNd::operator = (const TreeNd &nd){
			node = nd.node;
			isFirst = nd.isFirst;
		}
		TreeNd(const TreeNd &nd){
			node = nd.node;
			isFirst = nd.isFirst;
		}

	};
	vector<int> postOrder(TreeNode *root){
		vector<int> ret;
		if (!root) return ret;
		TreeNd *n = new TreeNd(root);
		stack<TreeNd* > s;
		s.push(n);
		while (!s.empty())
		{
			TreeNd *nd = s.top();
			if (!nd->isFirst)
			{
				ret.push_back(nd->node->val);
				s.pop();
			}
			else{
				nd->isFirst = false;
				if (nd->node->right){
					TreeNd *n2 = new TreeNd(nd->node->right);
					s.push(n2);
				}
				if (nd->node->left){
					TreeNd *n1 = new TreeNd(nd->node->left);
					s.push(n1);
				}
			}
		}
		return ret;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		TreeNode* root = NULL;
		if (preorder.empty()) return root;
		root = ConstructHelper(preorder, inorder, preorder.begin(), preorder.end()-1, inorder.begin(), inorder.end() - 1);
		return root;
	}
	TreeNode* ConstructHelper(vector<int>& preorder, vector<int>& inorder, vector<int>::iterator prestart, vector<int>::iterator preend, vector<int>::iterator instart, vector<int>::iterator inend)
	{
		if ((prestart <= preend) && (instart <= inend)){
			int rval = *prestart;
			TreeNode* root = new TreeNode(rval);
			vector<int>::iterator i = find(inorder.begin(), inorder.end(), rval);
			int span = i - instart;
			if (span>0){
				root->left = ConstructHelper(preorder, inorder, prestart + 1, prestart + span, instart, instart + span - 1);	
			}
				root->right = ConstructHelper(preorder, inorder, prestart + span + 1, preend, instart + span + 1, inend);

			return root;
		}
		else
			return NULL;
	}
	TreeNode* ConstructPostIn(vector<int>& postorder, vector<int>& inorder)
	{
		stack<TreeNode*> s;
		TreeNode* root = NULL,*ppost=NULL,*pin=NULL;
		if (postorder.empty() || postorder.size()!=inorder.size()) return root;
		int pos = inorder.size() - 1, i = 0, j = postorder.size()-1;
		root = new TreeNode(INT_MAX);
		s.push(root);
		while (pos<inorder.size()){
			if (s.top()->val == inorder[pos])
			{
				ppost = s.top();
				s.pop();
				pos--;
				//j--;
			}
			else if (ppost){
				pin = new TreeNode(postorder[j]);
				ppost->left = pin;
				s.push(pin);
				ppost = NULL;
				j--;
			}
			else
			{
				pin = new TreeNode(postorder[j]);
				s.top()->right = pin;
				s.push(pin);
				j--;
			}
		}
		ppost = root->right;
		delete root;
		return ppost;
	}


	vector<int> postOrderIV(TreeNode *root){
		vector<int> ret;
		if (!root) return ret;
		stack<TreeNode *> s;
		TreeNode *pre = root, *cur = NULL;
		s.push(root);
		while (!s.empty())
		{
			cur = s.top();
			if (cur->left == NULL&&cur->right == NULL || (pre == cur->left || pre == cur->right))
			{
				s.pop();
				ret.push_back(cur->val);
				pre = cur;
			}
			else
			{
				if (cur->left)
					s.push(cur->left);
				if (cur->right)
					s.push(cur->right);
			}
		}
		return ret;
	}

	~PreOrderTree();
};

