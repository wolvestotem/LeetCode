#include"../leetcode.h"

class Solution {
    vector<vector<pair<int,int>>> path;
public:
    bool dfs(vector<vector<char>>& board, int x, int y, vector<pair<int,int>>& p){
        if(x<0||y<0||x>=board.size()||y>=board[0].size()){
            path.push_back(p);
            return false;
        }
        if(board[x][y]=='X'||board[x][y]=='*')
            return true;
        board[x][y]='*';
        p.emplace_back(x,y);
        bool res =  dfs(board,x-1,y,p)&&dfs(board,x+1,y,p)&&dfs(board,x,y-1,p)&&dfs(board,x,y+1,p);
        board[x][y]='O';
        return res;
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O'){
                    vector<pair<int,int>> p;
                    bool res = dfs(board, i, j, p);
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++)
                board[i][j]='X';
        }
        for(int i=0;i<path.size();i++){
            for(auto pa:path[i]){
                board[pa.first][pa.second]='O';
            }
        }
    }
};