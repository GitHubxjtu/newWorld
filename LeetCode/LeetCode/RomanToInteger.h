#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class RomanToInteger
{
public:
	RomanToInteger();
	int romanToInt(string s) {
		int q = 0, b = 0, t = 0, g = 0;
		int pos = 0;
		while (pos<s.length()){
			switch (s[pos]){
			case 'M':
				q++;
				break;
			case 'C':
				if (s[pos + 1] == 'M')
				{
					b = 9;
					pos++;
				}
				else if (s[pos + 1] == 'D')
				{
					b = 4;
					pos++;
				}
				else
					b++;
				break;
			case 'D':
				b += 5;
				break;
			case 'X':
				if (s[pos + 1] == 'C')
				{
					t = 9;
					pos++;
				}
				else if (s[pos + 1] == 'L')
				{
					t = 4;
					pos++;
				}
				else
					t++;				
				break;
			case 'L':
				t += 5;
				break;
			case 'I':
				if (s[pos + 1] == 'X')
				{
					g = 9;
					pos++;
				}
				else if (s[pos + 1] == 'V')
				{
					g = 4;
					pos++;
				}
				else
					g++;
				break;
			case 'V':
				g += 5;
			}
			pos++;
		}
		return q * 1000 + b * 100 + t * 10 + g;
	}
	~RomanToInteger();
};

