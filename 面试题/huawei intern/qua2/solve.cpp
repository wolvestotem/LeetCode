#include"leetcode.h"

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int m = triangle.size();
		vector<int> temp(m+1, 0);
		vector<vector<int>> table(m+1, temp);
		table[1][1] = triangle[0][0];
		for (int n = 0; n < triangle.size(); n++) {
			table[n][0] = INT_MAX;
			table[n][n+1] = INT_MAX;
		}
		for (int n = 2; n < triangle.size(); n++) {
			for (int i = 1; i <= n; i++) {
				table[n][i] = triangle[n-1][i] + min(table[n - 1][i], table[n - 1][i - 1]);
			}
		}
		int min = INT_MAX;
		for (int i = 0; i < triangle.size(); i++) {
			if (table[triangle.size() - 1][i] < min)
				min = table[triangle.size() - 1][i];
		}
		return min;
	}
};