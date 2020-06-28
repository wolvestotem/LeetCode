#include"../leetcode.h"

class Solution {
    vector<vector<pair<int,int>>> path;
public:
    
    //Solution in discussion
    void solve(vector<vector<char>>& board){
        if(board.empty()) return;
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O')
                dfs(board,i,0);
            if(board[i][board[0].size()-1]=='O')
                dfs(board,i,board[0].size()-1);
        }
        
        for(int j=0;j<board[0].size();j++){
            if(board[0][j]=='O')
                dfs(board,0,j);
            if(board[board.size()-1][j]=='O')
                dfs(board,board.size()-1,j);
        }
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='*')
                    board[i][j]='O';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int x, int y){
        if(x<0||y<0||x>=board.size()||y>=board[0].size())
            return;
        if(board[x][y]=='X'|| board[x][y]=='*')
            return;
        board[x][y]='*';
        dfs(board,x-1,y);
        dfs(board,x+1,y);
        dfs(board,x,y-1);
        dfs(board,x,y+1);
    }
};