#include"../leetcode.h"

class Solution {
public:
    //Greedy solution: 每步的最大可达区域，不能低于当前位置
    bool canJump(vector<int>& nums){
        if(nums.empty()) return false;
        int maxjump = 0;
        for(int i=0;i<nums.size();i++){
            if(maxjump<i)
                return false;
            maxjump = max(maxjump,nums[i]+i);
        }
        return true;
    }
};