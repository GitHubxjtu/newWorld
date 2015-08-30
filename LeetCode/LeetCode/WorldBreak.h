#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;
class WorldBreak
{
public:
	WorldBreak();
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		int start =0,end = 1;
		while (end <= s.length()){
			string t = s.substr(start,end-start);
			if (wordDict.find(t) != wordDict.end()){
				start = end;
			}
			end++;
		}
		if (start == s.length()) return true;
		return false;
	}
	~WorldBreak();
};

