#pragma once
class Parentheses
{
public:
	Parentheses();
	int longestValidParenthesesI(string s) {
		stack<char> st;
		int ret = 0,pre = 0;
		int pos = 0;
		while (pos<s.length()){
			if (s[pos] == '(') {
				if (st.empty())
					st.push(s[pos]);
				else
				{
					pre = max(pre, ret);
					ret = 0;
				}

			}
			else if (s[pos] == ')'&&!st.empty()){
				st.pop();
				ret += 2;
			}
			else
			{
				pre = max(pre, ret);
				ret = 0;
			}
			pos++;
		}
		ret = max(pre,ret);
		return ret;
	}
	int longestValidParenthesesII(string s) {
		int len;
		for (len = s.length(); len>0; len--)
		{
			int pos = 0;
			while (pos<s.length() - len + 1){
				if (isValid(s, pos, len))
					return len;
				pos++;
			}
		}
		return 0;
	}
	bool isValid(string s, int pos, int n)
	{
		stack<char> st;
		while (pos<n){
			if (s[pos] == ')'){
				if (st.empty())return false;
				st.pop();
			}
			else{
				st.push(s[pos]);
			}
			pos++;
		}
		return st.empty();
	}
	int longestValidParentheses(string s) {
	}
	~Parentheses();
};

