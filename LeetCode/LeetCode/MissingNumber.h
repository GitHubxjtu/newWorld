#pragma once
class MissingNumber
{
public:
	MissingNumber();
	int missingNumber(vector<int> &nums)//ת��Ϊsinglenumber
	{
		int ans = nums.size();
		int i = 0;
		for (int num:nums)
		{
			ans ^= num;
			ans ^= i;
			i++;
		}
		return ans;
	}
	~MissingNumber();
};

