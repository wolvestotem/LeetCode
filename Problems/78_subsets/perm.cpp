#include"../leetcode.h"

class Solution {
    vector<vector<int>> result;
public:
    void recur(vector<int>& nums, vector<int>& path, int index){//reference减小时间空间复杂度
        int n = nums.size();
        if(index==n){
            result.push_back(path);
            return;
        }
        recur(nums,path,index+1);
        path.push_back(nums[index]);
        recur(nums,path,index+1);
        path.pop_back();//使用的是reference，使用后必须还原
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty()) return result;
        vector<int> path;
        recur(nums,path,0);
        return result;
    }
};