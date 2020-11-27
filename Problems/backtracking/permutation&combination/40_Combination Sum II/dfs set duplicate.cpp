#include"../leetcode.h"

class Solution {
    set<vector<int>> result;
    vector<vector<int>> res;
public:
    void dfs(vector<int>& candidates, vector<int>& path, int index, int target){
        if(target==0){
            result.insert(path);
            return;
        }
        if(target<0)
            return;
        if(index>=candidates.size())
            return;
        dfs(candidates,path,index+1,target);
        path.push_back(candidates[index]);
        dfs(candidates,path,index+1,target-candidates[index]);
        path.pop_back();
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty()) return res;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        dfs(candidates, path, 0, target);

        for(auto p:result){
            res.push_back(p);
        }
        return res;
    }
};