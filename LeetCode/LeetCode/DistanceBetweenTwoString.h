#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class DistanceBetweenTwoString
{
public:
	DistanceBetweenTwoString();
	int minDistanceII(string word1, string word2) {
		if (word1.empty())
			return word2.length();
		if (word2.empty())
			return word1.length();
		if (word1[0] == word2[0]){
			string s1 = word1.substr(1, word1.length() - 1);
			string s2 = word2.substr(1, word2.length() - 1);
			return minDistance(s1, s2);
		}
		else
		{
			string s1 = word1.substr(1, word1.length() - 1);
			string s2 = word2.substr(1, word2.length() - 1);
			int a = minDistance(s1, word2);
			int b = minDistance(s1, s2);
			int c = minDistance(word1, s2);
			return min(min(a, b), c) + 1;
		}
	}
	int minDistanceI(string s1,string s2){
		int l1 = s1.length(), l2 = s2.length() , ans = 0;
		vector<vector<int> > dis(l1 + 1, vector<int>(l2 + 1, 0));
		for (int i = 0; i <= l1; i++){
			dis[i][0] = i;
		}
		for (int i = 0; i <= l2; i++){
			dis[0][i] = i;
		}
		for (int i = 1; i <= l1;i++){
			for (int j = 1; j <= l2; j++){
				if (s1[i-1] != s2[j-1]){
				    dis[i][j] = min(min(dis[i - 1][j], dis[i - 1][j-1]),dis[i][j-1]);
					dis[i][j]++;
			    }
				else
				{
					dis[i][j] = dis[i-1][j-1];
				}
			}
		}
		ans = dis[l1][l2];
		return ans;
	}
	int minDistance(string s1,string s2)
	{
		int l1 = s1.length(), l2 = s2.length();
		vector<int> f(l2+1,0);
		for (int i = 0; i <= l2; i++)
			f[i] = i;
		for (int i = 1; i <= l1; i++)
		{
			int pre = i;
			for (int j = 1; j <= l2; j++){
				int cur;
				if (s1[i-1] == s2[j-1])
				{
					cur = f[j - 1];
				}
				else
				{
					cur = min(min(pre,f[j-1]),f[j]);
					cur++;
				}
				f[j - 1] = pre;
				pre = cur;
			}
			f[l2] = pre;
		}

		return f[l2];
	}
	~DistanceBetweenTwoString();
};

