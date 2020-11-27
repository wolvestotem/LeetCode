#include"../leetcode.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(!m || !n) return 0;
        vector<int> tem(n,0);
        vector<vector<int>> table(m,tem);
        //base case
        for(int i=0;i<m;i++)
            table[i][0] = 1;
        for(int j=0;j<n;j++)
            table[0][j] = 1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                table[i][j] = table[i][j-1] + table[i-1][j];
            }
        }
        return table[m-1][n-1];
    }
};