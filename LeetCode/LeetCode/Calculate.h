#pragma once
#include <sstream>
#include <iostream>
struct TreeNode{
	char c;
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(char t) :c(t), val(-1), left(NULL), right(NULL){}
	TreeNode(int x) :val(x), c('o'), left(NULL), right(NULL){}
};
class Calculate
{
public:
	Calculate();
	int calculate(string s) {
		int pos = 0, num = 0, sign = 1, ans = 0;
		stack<int> st;
		while (pos<s.length()){
			if (s[pos] == '+'){
				st.push(num*sign);
				sign = 1;
				num = 0;
			}
			else if (s[pos] == '-'){
				st.push(num*sign);
				sign = -1;
				num = 0;
			}
			else if (s[pos] == '(' || s[pos] == ')' || s[pos] == ' ')
			{

			}
			else{
				num *= 10;
				num += s[pos] - '0';
			}
			pos++;
		}
		st.push(num*sign);
		while (!st.empty()){
			ans += st.top();
			st.pop();
		}
		return ans;
	}
	int calculateIII(string s) {
		istringstream in('+' + s + '+');
		long long total = 0, term = 0, n;
		char op;
		while (in >> op) {
			if (op == '+' || op == '-') {
				total += term;
				in >> term;
				term *= (44 - op);
			}
			else {
				in >> n;
				if (op == '*')
					term *= n;
				else
					term /= n;
			}
		}
		return total;
	}
	int calculateII(string s) {
		int pos = 0, start = 0,  pre = -1,cur = -1,ans = 0;
		stack<char> st;
		stack<int> num;
		while (pos < s.length()){
			switch (s[pos]){
				case '+':
				case '-':
					if (st.empty()){
						st.push(s[pos]);
					}
					else{
						int prev = num.top();
						num.pop();
						cur = calString(st.top(), num.top(), prev);
						num.pop();
						st.pop();
						num.push(cur);
						while (!st.empty()){

							int prevp = num.top();
							num.pop();
							cur = calString(st.top(), num.top(), prevp);
							num.pop();
							num.push(cur);
							st.pop();

						}
						st.push(s[pos]);

					}
					break;

				case '*':
				case '/':
					if (st.empty()){
						st.push(s[pos]);
					}
					else if (st.top() == '*' || st.top() == '/'){
						int prev = num.top();
						num.pop();
						cur = calString(st.top(), num.top(), prev);
						num.pop();
						num.push(cur);
						st.pop();
						st.push(s[pos]);
					}
					else if (st.top() == '+' || st.top() == '-')
					{
						st.push(s[pos]);
					}
					break;
				case ' ':
					break;
				default:
					if (pos == 0 || (9<s[pos - 1] - '0') || (0>s[pos - 1] - '0'))
						start = pos;
					if ((9 < s[pos + 1] - '0') || (0 > s[pos + 1] - '0'))
					{
						string tt = s.substr(start, pos - start + 1);
						cur = atoi(tt.data());
						num.push(cur);
					}
					break;
			}
			pos++;
		}
		while (!st.empty()){

				int prev = num.top();
				num.pop();
				cur = calString(st.top(), num.top(),prev);
				num.pop();
				num.push(cur);
			    st.pop();

		}
		ans = num.top();
		return ans;
	}
	int calString(char s, int i, int j){
		switch (s){
		case '+':
			return i + j;
			break;

		case '-':
			return i - j;
			break;

		case '*':
			return i*j;
			break;

		case '/':
			return i / j;
			break;
		}
		return 0;
	}
	/*int calculate(string s) {
		int pos = 0, start = 0, cur = -1;
		TreeNode *root = NULL, *pcur=NULL;
		while (pos<s.length()){
			TreeNode *temp1 = new TreeNode('+');
			if (s[pos]=='+')
			{
				if (root&&root->left != NULL)
				{
					temp1->left = root;
					root = temp1;
					pcur = root;
				}
				else
				{
					root = temp1;
					root->left = new TreeNode(cur);
					pcur = root;
				}
			}
			else if (s[pos] == '-')
			{
				TreeNode *temp2 = new TreeNode('-');
				if (root&&root->left != NULL)
				{
					temp2->left = root;
					root = temp2;
					pcur = root;
				}
				else
				{
					root = temp2;
					root->left = new TreeNode(cur);
					pcur = root;
				}
			}
			else if (s[pos] == '*'){
				TreeNode *temp3 = new TreeNode('*');
				if (root&&root->left != NULL)
				{
					if (pcur && (pcur->c == '/' || pcur->c == '*'))
					{
						temp3->left = pcur;
						if (root == pcur)
							root = temp3;
						else
							root->right = temp3;
						pcur = temp3;
					}
					else{
					pcur = temp3;
					pcur->left = root->right;
					root->right = temp3;
					}
				}
				else
				{
					root = temp3;
					if (root)
					root->left = new TreeNode(cur);
					pcur = root;
				}

			} else if (s[pos] == '/')
			{
				TreeNode *temp4 = new TreeNode('/');
				if (root&&root->left != NULL)
				{
					if (pcur && (pcur->c == '/' || pcur->c == '*'))
					{
						temp4->left = pcur;
						if (root == pcur)
							root = temp4;
						else
							root->right = temp4;
						pcur = temp4;
					}
					else{
						pcur = temp4;
						pcur->left = root->right;
						root->right = temp4;
					}
				}
				else
				{
					root = temp4;
					if (root)
					root->left = new TreeNode(cur);
					pcur = root;
				}
			}
			else if (s[pos] == ' '){

			}
			else{

				if (pos == 0 ||( 9<s[pos - 1] - '0' )||( 0>s[pos - 1]-'0'))
					start = pos;
				if ((9<s[pos + 1] - '0') || (0>s[pos + 1]-'0'))
				{
					string tt = s.substr(start, pos - start + 1);
					cur = atoi(tt.data());
				if (pcur&&(!pcur->right))
					pcur->right = new TreeNode(cur);
				}
			}
				pos++;
		}
	int ans = calTree(root);
	delTree(root);
	return ans;
}
	void delTree(TreeNode* root){
		if (!root) return;
		delTree(root->left);
		delTree(root->right);
		delete root;
	}
	int calTree(TreeNode *root){
	if (!root)
			return 0;
	if (root && (!root->left) && (!root->right)){
		return root->val;
	}
	int vl = calTree(root->left);
	int vr = calTree(root->right);
	return calString(root->c, vl, vr);
}
int calString(char s, int i, int j){
	switch (s){
	case '+':
		return i + j;
		break;

	case '-':
		return i - j;
		break;

	case '*':
		return i*j;
		break;

	case '/':
		return i / j;
		break;
	}
	return 0;
}*/
	~Calculate();
};

