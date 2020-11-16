#include"../leetcode.h"

class Solution {
    vector<vector<int>> res;
public:
    void dfs(vector<int>& nums, int index, int k, vector<int>& path){
        if(k==0){
            res.push_back(path);
            return;
        }
        if(index>=nums.size())
            return;
        
        for(int i=index;i<nums.size();i++){
            path.push_back(nums[i]);
            dfs(nums,i+1,k-1,path);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        int index=0;
        vector<int> nums,path;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        dfs(nums,index,k,path);
        return res;
    }
};