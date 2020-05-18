#include"../leetcode.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //Transpose and reverse
        
        //Transpose
        if(matrix.empty())
            return;
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //reverse
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};