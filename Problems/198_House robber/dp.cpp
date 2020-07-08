#include"../leetcode.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> table(nums.size()+1,0);
        table[1] = nums[0];
        for(int i=1;i<nums.size();i++){
            table[i+1] = max(table[i-1]+nums[i], table[i]);
        }
        return table[nums.size()];
    }
};