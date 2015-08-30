#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class SpiralMatrix
{
public:
	SpiralMatrix();
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		if (matrix.empty()) return ans;
		int n = matrix.size();
		int m = matrix[0].size();
		int i = 0;
		while (i<m - i){
			int j = i;
			while (j<m - i){
				ans.push_back(matrix[i][j]);
				j++;
			}
			j = i + 1;
			if (j >= n - i) break;
			while (j<n - i)
			{
				ans.push_back(matrix[j][m - i - 1]);
				j++;
			}
			j = m - i - 2;
			if (j < i) break;
			while (j>=i)
			{
				ans.push_back(matrix[n - i - 1][j]);
				j--;
			}
			j = n - i - 2;
			if (j <= i) break;
			while (j>i)
			{
				ans.push_back(matrix[j][i]);
				j--;
			}
			i++;
		}
		return ans;
	}
	vector<vector<int>> generateMatrix(int n) {
		if (n < 1) return vector<vector<int>>();
		vector<vector<int>> matrix(n,vector<int>(n,1));
		int l = 0, r = n - 1, u = 0, d = n - 1;
		int i = 0, j = 0;
		while (l <= r&&u <= d){
			while (j < r){
				j++;
				matrix[i][j] = matrix[i][j - 1] + 1;
			}
			u++;
			while (i < d){
				i++;
				matrix[i][j] = matrix[i - 1][j] + 1;
			}
			r--;
			while (j >l){
				matrix[i][j-1] = matrix[i][j] + 1;
				j--;
			}
			d--;
			while (i >u){
				matrix[i-1][j] = matrix[i][j] + 1;
				i--;
			}
			l++;
		}
		return matrix;
	}
	~SpiralMatrix();
};

