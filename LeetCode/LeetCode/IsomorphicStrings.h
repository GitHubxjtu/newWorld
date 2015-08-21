#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class IsomorphicStrings
{
public:
	IsomorphicStrings();
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char> mp;
		for (int i = 0; i < s.size(); i++){
			if (mp.find(s[i]) != mp.end()){
				if (mp[s[i]] != t[i])
					return false;
			}
			else
				mp[s[i]] = t[i];
		}
		mp.clear();
		for (int i = 0; i < t.size(); i++){
			if (mp.find(t[i]) != mp.end()){
				if (mp[t[i]] != s[i])
					return false;
			}
			else
				mp[t[i]] = s[i];
		}
		mp.clear();
		return true;
	}
	bool isIsomorphicII(string s, string t) {
		int m1[256] = { 0 }, m2[256] = { 0 }, n = s.size();
		for (int i = 0; i < n; ++i) {
			if (m1[s[i]] != m2[t[i]]) return false;
			m1[s[i]] = i + 1;
			m2[t[i]] = i + 1;
		}
		return true;
	}
	virtual ~IsomorphicStrings();
};

