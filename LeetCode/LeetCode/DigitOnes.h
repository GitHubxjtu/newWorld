#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class DigitOnes
{
public:
	DigitOnes();
	int countDigitOne(int n) {
/*		int  remain = 0, digit = 1;
		int ans = 0;
		while (n){
			ans += ( n / 10)*digit;
			switch (n % 10){
			case 0:
				break;
			case 1:
				ans += (remain+1);
				break;
			default:
				ans += digit;
				break;
			}
			n = n / 10;
			digit *= 10;
			remain += digit*(n % 10);
		}*/
		long ans = 0;
		for (long m = 1; m <= n; m *= 10)
		{
			ans += (n / m + 8) / 10 * m + ((n / m )% 10 == 1)*(n%m+1);
		}

		return ans;
	}
	~DigitOnes();
};

