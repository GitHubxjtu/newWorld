#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class ZigZagString
{
public:
	ZigZagString();
	string convert(string s, int numRows) {
		if (numRows <= 1) return s;
		string ret;
		int row = 1, pos2 = 0, pos = 0;
		while (pos<s.length()){
			ret.append(1, s[pos]);
			pos += 2 * (numRows - 1);
		}
		while (row<numRows - 1)
		{
			pos = row;
			pos2 = 2 * (numRows - 1) - row;
			while (pos<s.length()){
				ret.append(1, s[pos]);
				if (pos2<s.length())
					ret.append(1, s[pos2]);
				pos += 2 * (numRows - 1);
				pos2 += 2 * (numRows - 1);
			}
			row++;
		}
		pos = numRows - 1;
		while (0<pos&&pos<s.length()){
			ret.append(1, s[pos]);
			pos += 2 * (numRows - 1);
		}
		return ret;
	}
	~ZigZagString();
};

