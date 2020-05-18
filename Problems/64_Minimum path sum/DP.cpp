#include"../leetcode.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> table(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1)//初始化第1行，第1列
                    table[i][j] = table[i][j-1]+grid[i-1][j-1];
                else if(j==1)
                    table[i][j] = table[i-1][j]+grid[i-1][j-1];
                else
                    table[i][j] = min(table[i-1][j],table[i][j-1])+grid[i-1][j-1];//递推式
            }
        }
        return table[m][n];
    }
};