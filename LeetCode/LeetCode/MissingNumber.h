#pragma once
class MissingNumber
{
public:
	MissingNumber();
	int missingNumber(vector<int> &nums)//×ª»¯Îªsinglenumber
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

