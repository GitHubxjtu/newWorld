// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "permute.h"

int _tmain(int argc, _TCHAR* argv[])
{
	/*TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right = new TreeNode(5);
	root->right->right = new TreeNode(6);
	root->right->left = new TreeNode(8);
	root->left->right = new TreeNode(7);
	PreOrderTree b;
	vector<int> in = b.recurInorder(root);
	vector<int> pre = b.recurPreorder(root);
	vector<int> post = b.recurPostorder(root);
	cout << "inorder:"<<endl;
	for (int i = 0; i < in.size(); i++){
		printf("%d", in[i]);
	}
	cout << endl<<"preorder:"<<endl;
	for (int i = 0; i < in.size(); i++){
		printf("%d", pre[i]);
	}
	cout << endl<<"postOrder"<<endl;
	for (int i = 0; i < in.size(); i++){
		printf("%d", post[i]);
	}*/
/*	ReverseLinkList r;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	ListNode *ans = r.reverseBetween(head,2,3);
	int i = 0;
	while (ans&&i<4){
		printf("%d", ans->val);
		ans = ans->next;
		i++;
	}
	
	SpiralMatrix d;
	vector<vector<int>>nums = d.generateMatrix(4);
	vector<vector<int>>n = { { 6, 7, 9 } };
	for (int i = 0; i < nums.size()-1; i++)
	{
		for (int j = 0; j < nums[i].size(); j++){
			printf("%d\t",nums[i][j]);
		}
		cout << endl;
	}
	cout <<"************************************************"<< endl;
	vector<int> order = d.spiralOrder(n);
	for (int i = 0; i < order.size();i++)
		printf("%d\t", order[i]);
	
	permute p;
	vector<int> n = {1,2,3,4,5};
	vector<vector<int>>nums = p.permutev(n);

	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums[i].size(); j++){
			printf("%d\t", nums[i][j]);
		}
		cout << endl;
	}
	IsomorphicStrings is;
	string s = "apple";
	string t = "tllgt";
	if (is.isIsomorphic(s, t))
		cout << "Isomorphic Strings";
	else
	cout << "not Isomorphic Strings";
	RomanToInteger r;
	string s = "MMMCMXCIV";
	int ret = r.romanToInt(s);
	printf("%d",ret);
	ZigZagString z;
	string s= "abcdefghijklmnopqrstuvwxyz";
	cout << z.convert(s,1);
	
	MaxPath m;
	TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right = new TreeNode(5);
	root->right->right = new TreeNode(6);
	root->right->left = new TreeNode(8);
	root->left->right = new TreeNode(7);
	root->right->left->left = new TreeNode(11);
	root->right->right->left = new TreeNode(12);
	root->left->right->left = new TreeNode(7);

	int ans = m.maxPathSum(root);
	printf("%d",ans);
	TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right = new TreeNode(5);
	root->right->right = new TreeNode(6);
	root->right->left = new TreeNode(8);
	root->left->right = new TreeNode(7);
	root->right->left->left = new TreeNode(11);
	root->right->right->left = new TreeNode(12);
	root->left->right->left = new TreeNode(9);
	PreOrderTree p;
	vector<int> ans = p.postOrder(root);
	for (int i = 0; i < ans.size();i++)
	printf("%d ", ans[i]); 
	Calculate c;
	string s = " 30 ";
	int ans = c.calculate(s);
	printf("%d",ans);

	PreOrderTree b;
	vector<int> in = { 3,4,9,8,2,6,7,5};
	vector<int> post =  {3,9,8,4,6,5,7,2};
	TreeNode *root = b.ConstructPostIn(post, in);
	treeLevelOrder t;
	t.levelOrderBottom(root);
    CourseSchedule c;
	int numCourses = 2;
	vector<pair<int, int>> prerequisites;
	prerequisites.push_back(make_pair(0, 1));
	//prerequisites.push_back(make_pair(2, 0));
	//prerequisites.push_back(make_pair(3, 1));
	//prerequisites.push_back(make_pair(3, 2));
	//prerequisites.push_back(make_pair(4, 3));
	vector<int> ans;
	ans = c.findOrder(numCourses,prerequisites);

	for (int i = 0; i < ans.size(); i++)
		printf("%d", ans[i]);*/
permute p;

     //vector<int> nums = {1,2,3,4};
     //p.permutev(nums);
string s = p.getPermutation(4, 5);
cout << s;
	while(1);
	return 0;
}

