#include"../leetcode.h"

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums){
        if(nums.empty()) return 0;
        vector<int> d(nums.size()+1,0);
        int len=1;
        d[len] = nums[0];
        for(int i=1;i<nums.size();i++){
            if(d[len]<nums[i]){
                len++;
                d[len] = nums[i];
            }
            else{
                int left(1),right(len+1);
                while(left<right){
                    int mid = (left+right)>>1;
                    if(d[mid]==nums[i])
                        right = mid;
                    else if(d[mid]<nums[i])
                        left = mid+1;
                    else
                        right = mid;
                }
                d[left] = nums[i];
            }
        }
        return len;
    }
};