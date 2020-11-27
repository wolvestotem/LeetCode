## 题目

212. Word Search II
Hard

Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

## 题解

使用word search的接口，只不过比较了多个string在grid中是否存在问题

```C++

class Solution {
public:
    bool dfs(vector<vector<char>>& board, vector<string>& words, int index, int wordindex, int x, int y){
        int m=board.size();
        int n=board[0].size();
        if(x<0||x>=m||y<0||y>=n)
            return false;
        if(board[x][y] != words[wordindex][index])
            return false;
        if(index>=words[wordindex].size()-1)
            return true;
        
        char temp = board[x][y];
        board[x][y]='*';
        bool result = dfs(board,words,index+1,wordindex,x+1,y) || dfs(board,words,index+1,wordindex,x-1,y) || dfs(board,words,index+1,wordindex,x,y+1) || dfs(board,words,index+1,wordindex,x,y-1);
        board[x][y] = temp;
        return result;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        for(int i=0;i<words.size();i++){
            bool flag=false;
            for(int x=0;x<board.size();x++){
                for(int y=0;y<board[0].size();y++){
                    if(board[x][y]==words[i][0] && !flag)
                       if(dfs(board,words,0,i,x,y)){
                           result.push_back(words[i]);
                           flag=true;
                       }
                }
            }
        }
        return result;
    }
};
```
