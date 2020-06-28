#include"../leetcode.h"

class Solution {
    int result = INT_MAX;
public:
    void dfs(string endWord, vector<string>& wordList, int index, int length, vector<vector<int>>& table){
        if(wordList[index]==endWord){
            result = min(result, length);
            return;
        }
        for(int i=0;i<wordList.size();i++){
            if(table[index][i]==1){
                vector<int> tem(table.size(),0);
                for(int i=0;i<table.size();i++)
                    tem[i] = table[i][index];
                for(int i=0;i<wordList.size();i++)
                    table[i][index]=0;
                dfs(endWord, wordList, i, length+1, table);
                for(int i=0;i<table.size();i++)
                    table[i][index] = tem[i];
            }
        }
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.empty()) return 0;
        bool have=false;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==endWord)
                have=true;
        }
        if(!have) return 0;
        
        wordList.insert(wordList.begin(),beginWord);
        vector<vector<int>> table(wordList.size(),vector<int>(wordList.size(),0));
        int n = beginWord.size();
        for(int i=0;i<wordList.size();i++){
            for(int j=i;j<wordList.size();j++){
                int diff=0;
                for(int k=0;k<n;k++){
                    if(wordList[i][k]!=wordList[j][k])
                        diff++;
                }
                if(diff==1){
                    table[i][j]=1;
                    table[j][i]=1;
                }
            }
        }

        dfs(endWord, wordList, 0, 0, table);
        if(result==INT_MAX) 
            return 0;

        return result+1;
    }
};