#include"../leetcode.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty())
            return res;
        
        queue<int> q;
        q.push(0);
        q.push(1);
        q.push(2);
        q.push(3);
        int i(0),j(0);
        vector<vector<int>> visit(matrix.size(),vector<int>(matrix[0].size(),0));
        
        if(matrix.size()==1 || matrix[0].size()==1){
            for(int i=0;i<matrix.size();i++){
                for(int j=0;j<matrix[0].size();j++){
                    res.push_back(matrix[i][j]);
                }
            }
            return res;
        }
        
        while(true){
            int mode = q.front();
            q.pop();
            q.push(mode);
            if(mode==0){
                bool have=false;
                while(j+1<matrix[0].size() && !visit[i][j+1]){
                    visit[i][j]=1;
                    res.push_back(matrix[i][j]);
                    j++;
                    have=true;
                }
                if(!have) break;
            }
            if(mode==1){
                bool have=false;
                while(i+1<matrix.size() && !visit[i+1][j]){
                    visit[i][j]=1;
                    res.push_back(matrix[i][j]);
                    i++;
                    have=true;
                }
                if(!have) break;
            }
            if(mode==2){
                bool have=false;
                while(j-1>=0 && !visit[i][j-1]){
                    visit[i][j]=1;
                    res.push_back(matrix[i][j]);
                    j--;
                    have=true;
                }
                if(!have) break;
            }
            if(mode==3){
                bool have=false;
                while(i-1>=0 && !visit[i-1][j]){
                    visit[i][j]=1;
                    res.push_back(matrix[i][j]);
                    i--;
                    have=true;
                }
                if(!have) break;
            }
        }
        res.push_back(matrix[i][j]);
        return res;
    }
};