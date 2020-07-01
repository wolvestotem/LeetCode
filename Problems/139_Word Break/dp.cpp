#include"../leetcode.h"
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> table(s.size(),false);
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        for(int i=0;i<s.size();i++){
            for(int j=0;j<=i;j++){
                if(j==0){
                    string sub = s.substr(0,i+1);
                    if(dict.find(sub)!=dict.end()){
                        table[i]=true;
                        continue;
                    }
                }
                if(table[j]){
                    string sub = s.substr(j+1,i-j);
                    if(dict.find(sub)!=dict.end()){
                        table[i]=true;
                    }
                }
            }
        }
        return table[s.size()-1];
    }
};