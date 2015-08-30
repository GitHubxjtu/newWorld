#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class BestTimeBuySellStock
{
public:
	BestTimeBuySellStock();
	int maxProfit(vector<int>& prices) {
		int maxProfit = 0;
		int minBuy = INT_MAX;
		for (int i = 0; i<prices.size(); i++)
		{
			minBuy = min(minBuy,prices[i]);
			maxProfit = max(maxProfit,prices[i]-minBuy);
		}
		return maxProfit;
	}
	int maxProfitII(vector<int>& prices) {
		int maxProfit = 0;
		for (int i = 0; i<prices.size() - 1; i++)
		{
			if (prices[i + 1] - prices[i]>0)
				maxProfit += prices[i + 1] - prices[i];
		}
		return maxProfit;
	}
	int maxProfitIII(vector<int>& prices) {
		int max1=0, max2=0;
		int minBuy = INT_MAX;
		for (int i = 0; i<prices.size() - 1; i++)
		{

		}
		return max1 + max2;

	}
	~BestTimeBuySellStock();
};

