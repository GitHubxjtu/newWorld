#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
class ValidParentheses
{
public:
	ValidParentheses();
	bool isValid(string s) {
		if (s.empty()) return true;
		stack<char> t;
		int pos = 0;
		while (pos<s.length())
		{
			if (s[pos] == '(' || s[pos] == '[' || s[pos] == '{'){
				t.push(s[pos]);
				pos++;
			}
			else if (!t.empty())
			{
				if ((s[pos] == ')'&&t.top() == '(') || (s[pos] == ']'&&t.top() == '[') || (s[pos] == '}'&&t.top() == '{'))
				{
					t.pop();
					pos++;
				}
			}
			else
				return false;
		}
		return t.empty();
	}
	virtual ~ValidParentheses();
};

