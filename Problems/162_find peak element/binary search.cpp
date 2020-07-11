#include"../leetcode.h"

class Solution {
public:
    
    int findPeakElement(vector<int>& nums) {
        
        if(nums.size()==1) return 0;
        int left(0),right(nums.size());
        while(left<right){
            int mid = (left+right)>>1;
            if((mid==0&&nums[mid]>nums[mid+1])||(mid==nums.size()-1&&nums[mid]>nums[mid-1])||(mid!=0&&mid!=nums.size()-1&&nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])){
                return mid;
            }
            else if(mid!=0&&nums[mid]<nums[mid-1]){
                right = mid;
            }
            else
                left = mid+1;
        }
        return left;
    }
};