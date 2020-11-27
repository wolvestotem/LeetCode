#include"../leetcode.h"

class Solution {
    vector<vector<int>> res;
public:
    void dfs(vector<pair<int,int>>& fre, int target, int index, vector<int>& path){
        if(target==0){
            res.push_back(path);
            return;
        }
        if(index==fre.size())
            return;
        if(target<0)
            return;
        
        dfs(fre,target,index+1,path);
        int most = min(target/fre[index].first,fre[index].second);
        for(int i=1;i<=most;i++){
            path.push_back(fre[index].first);
            dfs(fre,target-i*fre[index].first,index+1,path);
        }
        for(int i=1;i<=most;i++){
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<pair<int,int>> fre;
        sort(candidates.begin(),candidates.end());
        for(int i:candidates){
            if(fre.empty() || fre.back().first!=i)
                fre.emplace_back(i,1);
            else{
                fre.back().second++;
            }
        }
        vector<int> path;
        int index=0;
        dfs(fre,target,index,path);
        return res;
    }
};