#include"../leetcode.h"

class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    void recur(vector<int>& candidates, int target, vector<int>& nums, int rank);
};

void Solution::recur(vector<int>& candidates, int target, vector<int>& nums, int rank){
    if(target==0)
        result.push_back(nums);
    if(target<0)
        return;
    for(int i=rank; i<candidates.size();i++){//使用rank限制使用rank更小的元素perm
        if(target-candidates[i]>=0){
            nums.push_back(candidates[i]);
            recur(candidates, target-candidates[i], nums, i);//i，因为同一元素可以重复使用，但是不能用之前的元素
            nums.pop_back();
        }
    }
}

vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target){
    if(candidates.empty()) return result;
    vector<int> nums;
    recur(candidates, target, nums, 0);
    return result;
}