#pragma once
#include "stdafx.h"

#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class PalindromePartitioning
{
public:
	PalindromePartitioning();  
	vector<vector<string>> partition(string s) {
		vector<vector<string> > ret;
		if (s.empty()) return ret;
		vector<string> temp;
		int pos = 0;
		int end = 0;
		helper(pos,end, s, ret, temp);
		return ret;
	}
	void helper(int pos, int end, string s, vector<vector<string> > &ans, vector<string> &temp)
	{
		if (end == s.length())
		{
			ans.push_back(temp);
			return;
		}
		while (end<s.length()){
			if (isPalindrome(pos, end, s))
			{
				string ss = s.substr(pos, end - pos + 1);
				temp.push_back(ss);
				helper(end + 1, end + 1, s, ans, temp);
				temp.pop_back();
			}
			end++;
		}
	}
	bool isPalindrome(int i, int j, string s){
		if (i<0 || j >= s.length()) return false;
		while (i <= j)
		{
			if (s[i] != s[j])
			{
				return false;
			}
			else
			{
				i++;
				j--;
			}
		}
		return true;
	}

	virtual ~PalindromePartitioning();

};

