#include"../leetcode.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> record;
        if(matrix.empty()) return;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0)
                    record.emplace_back(i,j);
            }
        }
        for(auto p:record){
            for(int i=0;i<matrix.size();i++)
                matrix[i][p.second]=0;
            for(int j=0;j<matrix[0].size();j++)
                matrix[p.first][j]=0;
        }
    }
};