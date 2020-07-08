#include"../leetcode.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> table(nums.size(),1);

        for(int i=1;i<nums.size();i++){
            int max_ = 0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                    max_ = max(max_, table[j]);
            }
            table[i] = max_+1;
        }
        int m=0;
        for(auto i:table){
            m = max(m,i);
        }
        return m;
    }
};