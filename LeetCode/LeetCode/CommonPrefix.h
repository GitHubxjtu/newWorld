#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class CommonPrefix
{
public:
	CommonPrefix();
	string longestCommonPrefix(vector<string>& strs) {
		string CommonPrefix;
		if (strs.empty()) return CommonPrefix;
		int pos = 0;
		bool flag = false;
		while (pos<strs[0].length()){
			char c = strs[0][pos];
			for (int i = 1; i<strs.size(); i++)
			{
				if (strs[i].length() <= pos)
					return CommonPrefix;
				if (strs[i][pos] != c)
					return CommonPrefix;
			}
			CommonPrefix.append(1, c);
			pos++;
		}
		return CommonPrefix;
	}
	~CommonPrefix();
};

