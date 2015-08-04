#pragma once
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class minPath
{
public:
	minPath();
	int minPathSum1(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> minPath(n, vector<int>(m, 0));
		minPath[0][0] = grid[0][0];
		for (int i = 1; i<n; i++) minPath[i][0] = minPath[i-1][0]+grid[i][0];
		for (int i = 1; i<m; i++) minPath[0][i] = minPath[0][i-1]+grid[0][i];
		for (int i = 1; i <n; i++)
		{
			for (int j = 1; j<m; j++)
			{
				minPath[i][j] = min(minPath[i][j - 1], minPath[i - 1][j]) + grid[i][j];
			}
		}
		return minPath[n - 1][m - 1];
	}
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<int> pre(m, grid[0][0]);
		vector<int> cur(m, 0);
		for (int i = 1; i<m; i++)
		{
			pre[i] = pre[i - 1] + grid[i][0];
		}
		for (int i = 1; i < n; i++)
		{
			cur[0] = pre[0] + grid[0][i];
			for (int j = 1; j<m; j++)
			{
				cur[j] = min(pre[j], cur[j - 1]) + grid[j][i];
			}
			swap(cur, pre);
		}
		return pre[m - 1];
	}
	int minPathSum2(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<int> pre(m, grid[0][0]);
		vector<int> cur(m, 0);
		for (int i = 1; i < m; i++)
			pre[i] = pre[i - 1] + grid[i][0];
		for (int j = 1; j < n; j++) {
			cur[0] = pre[0] + grid[0][j];
			for (int i = 1; i < m; i++)
				cur[i] = min(cur[i - 1], pre[i]) + grid[i][j];
			swap(pre, cur);
		}
		return pre[m - 1];
	}
	virtual ~minPath();
};

