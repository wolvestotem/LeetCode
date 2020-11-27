#include"../leetcode.h"


class Solution{
    int LCS(vector<int>& nums){
        if(nums.empty()) return 0;
        if(nums.size()==1) return 1;
        vector<int> table(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                    table[i] = max(table[i],table[j]+1);
            }
        }
        int res=0;
        for(int i=0;i<nums.size();i++){
            res = max(res,table[i]);
        }
        return res;
    }
};