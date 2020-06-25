#include"../leetcode.h"

class Solution {
    vector<vector<string>> result;
    vector<vector<int>> table;
public:
    void dfs(string s, int index, vector<string>& path){
        if(index==s.size()){
            result.push_back(path);
            return;
        }
        int n=table.size();
        for(int i=0;i<n;i++){
            if(table[index][i]){
                path.push_back(s.substr(index,i-index+1));
                dfs(s, i+1, path);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        if(s.empty()) return result;
        int n = s.size();
        table = vector<vector<int>>(n,vector<int>(n,0));
        for(int j=0;j<s.size();j++){
            for(int i=s.size()-1;i>=0;i--){
                if(i==j)
                    table[i][j]=1;
                else if(j==i+1)
                    table[i][j] = (s[i]==s[j])?1:0;
                else if(j>i){
                    table[i][j] = table[i+1][j-1] && (s[i]==s[j]);
                }
            }
        }
        
        vector<string> path;
        dfs(s,0,path);
        return result;
    }
};