#include"../leetcode.h"

class Solution {
    string s;
public:
    bool dfs(vector<vector<char>>& board, int index, int x, int y){//返回bool类型
        bool result;
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size())//临界条件
            return false;
        if(s[index]!=board[x][y])
            return false;
        if(index>=s.size()-1) 
            return true;
        char temp = board[x][y];
        board[x][y] = '$';//---------------标识走过的路
        result = dfs(board,index+1,x-1,y) || dfs(board,index+1,x+1,y) || dfs(board,index+1,x,y-1) || dfs(board,index+1,x,y+1);
        board[x][y]=temp;//----------------还原路程
        return result;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        s = word;
        int m = board.size();
        int n = board[0].size();
        bool result = false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==s[0])
                    result = dfs(board,0,i,j);
                if(result)
                    return true;
            }
        }
        return false;
    }
};