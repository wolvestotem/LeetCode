#include"../leetcode.h"

class Solution {
    vector<string> res;
public:
    void dfs(string s, unordered_set<string>& dict, vector<int>& table, string path, int index){
        if(index==s.size()){
            path.pop_back();
            res.push_back(path);
            return;
        }
        string sub,tem;
        for(int i=index;i<s.size();i++){
            if(table[i]){
                sub = s.substr(index, i-index+1);
                if(dict.find(sub)!=dict.end()){
                    tem = path;
                    path = path+sub+" ";
                    dfs(s, dict, table, path, i+1);
                    path = tem;
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<int> table(s.size(),0);
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        for(int i=0;i<s.size();i++){
            string sub = s.substr(0,i+1);
            if(dict.find(sub)!=dict.end())
                table[i]=1;
        }
        for(int i=0;i<s.size();i++){
            for(int j=0;j<i&&!table[i];j++){
                if(table[j]){
                    string sub = s.substr(j+1,i-j);
                    if(dict.find(sub)!=dict.end()){
                        table[i]=1;
                        break;
                    }
                }
            }
        }
        string path;
        if(table[s.size()-1]==0)
            return res;
        dfs(s, dict, table, path, 0);
        return res;
    }
};