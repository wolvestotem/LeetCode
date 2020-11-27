#include"../leetcode.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> table(m, vector<int>(n,0));
        
        //base case
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1])
            return 0;
        table[0][0] = 1;
        for(int i=1;i<m;i++){
            table[i][0] = (obstacleGrid[i][0])? 0 : table[i-1][0];
        }
        for(int j=1;j<n;j++){
            table[0][j] = (obstacleGrid[0][j])? 0 : table[0][j-1];
        }
        

        //recurse 
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                table[i][j] = (obstacleGrid[i][j])? 0 : table[i][j-1]+table[i-1][j];
            }
        }
        
        return table[m-1][n-1];
        
    }
};