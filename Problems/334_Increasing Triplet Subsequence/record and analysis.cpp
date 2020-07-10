#include"../leetcode.h"

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3) return false;
        int fir = nums[0];
        int sec = INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>sec)
                return true;
            if(nums[i]>fir)
                sec = min(sec,nums[i]);
            else
                fir = min(fir,nums[i]);
        }
        return false;
    }
};