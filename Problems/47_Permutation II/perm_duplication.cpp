#include"../leetcode.h"

class Solution {
    vector<vector<int>> res;
public:
    void recur(vector<int>& nums, int index,vector<int>& path, unordered_set<int>& m){
        if(index==nums.size()){
            res.push_back(path);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(m.count(i))
                continue;
            if(i>0 && nums[i]==nums[i-1] && !m.count(i-1))
                continue;
            m.insert(i);
            path.push_back(nums[i]);
            recur(nums,index+1,path,m);
            path.pop_back();
            m.erase(i);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path;
        int index=0;
        unordered_set<int> m;
        sort(nums.begin(),nums.end());
        recur(nums,index,path,m);
        return res;
    }
};