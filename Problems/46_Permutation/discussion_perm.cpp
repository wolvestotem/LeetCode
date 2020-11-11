#include"../leetcode.h"

//Discussion Solution
class Solution {
    vector<vector<int>> res;
public:
    void recur(vector<int>& nums, int curr){
        if(curr==nums.size()-1){
            res.push_back(nums);
            return;
        }
        
        for(int i=curr;i<nums.size();i++){
            swap(nums[curr],nums[i]);
            recur(nums,curr+1);
            swap(nums[curr],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int curr(0);
        recur(nums,curr);
        return res;
    }
};