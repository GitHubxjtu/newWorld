#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;
class strStr
{
public:
	strStr();

	int isstrStr(string haystack, string needle) {
		int nlength = needle.length();
		int hlength = haystack.length();
		if (hlength < nlength || haystack.empty()) return -1;
		if (needle.empty()) return 0;
		int pos = 0;
		while (pos < hlength - nlength+1){
			string s = haystack.substr(pos++, nlength);
			if (s == needle)
				return pos;
		}
		return -1;
	}
	~strStr();
};

