#pragma once
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class LetterCombinationsofaPhoneNumber
{
public:
	LetterCombinationsofaPhoneNumber();
	vector<string> letterCombinations(string digits) {
		const vector<string> option = { " ", "\'", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> ans;
		string temp;
		int count = 0;
		helper(ans,temp,option,count,digits.length(),digits);
		return ans;
	}
	void helper(vector<string> &ans, string &temp, const vector<string> option, int cur, int length, string digits){
		if (cur == length){
			ans.push_back(temp);
			return;
		}
		int i = 0;
		while (i<option[digits[cur] - '0'].length()){
			temp.append(1, option[digits[cur] - '0'][i++]);
			helper(ans, temp, option, cur + 1, length, digits);
			temp.erase(temp.end()-1);
		}
	}
	~LetterCombinationsofaPhoneNumber();
};

