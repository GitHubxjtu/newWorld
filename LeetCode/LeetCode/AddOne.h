#pragma once
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class AddOne
{
public:
	AddOne();
	vector<int> plusOne(vector<int>& digits) {
		vector<int> ret;
		int inc = 0, cur;
		cur = (1 + inc + digits[digits.size() - 1]) % 10;
		inc = (1 + digits[digits.size() - 1]) / 10;
		digits[digits.size() - 1] = cur;
		for (int i = digits.size() - 2; i >= 0; i--){
			cur = (inc + digits[i]) % 10;
			inc = (inc + digits[i]) / 10;
			digits[i] = cur;
		}
		if (inc)
			ret.push_back(inc);

		for (int i = 0; i<digits.size(); i++){
			ret.push_back(digits[i]);
		}
		return ret;
	}
	~AddOne();
};

