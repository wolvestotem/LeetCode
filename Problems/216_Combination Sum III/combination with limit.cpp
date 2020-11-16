#include"../leetcode.h"

class Solution {
    vector<vector<int>> res;
public:
    void dfs(vector<int>& nums, int k, int index, int n, vector<int>& path){
        if(k==0 && n==0){
            res.push_back(path);
            return;
        }
        if(index>=nums.size())
            return;
        if(n<0)
            return;
        
        for(int i=index;i<nums.size();i++){
            path.push_back(nums[i]);
            dfs(nums,k-1,i+1,n-nums[i],path);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums,path;
        for(int i=1;i<10;i++){
            nums.push_back(i);
        }
        int index=0;
        dfs(nums,k,index,n,path);
        return res;
    }
};