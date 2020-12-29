#include"../leetcode.h"

int binary_search_val(vector<int>& nums, int target){
    int left(0),right(nums.size());
    
    while(left<right){
        int mi = (left+right)>>1;
        if(nums[mi]==target)
            return mi;
        else if(nums[mi]<target)
            right = mi;
        else if(target<nums[mi])
            left = mi+1;
    }
    return -1;
}

int binary_search_left_inv(vector<int>& nums, int target){
    int left(0),right(nums.size());
    
    while(left<right){
        int mi = (left+right)>>1;
        if(nums[mi]==target)
            right = mi;
        else if(nums[mi]<target)
            left = mi+1;
        else if(target<nums[mi])
            right = mi;
    }
    //left [0,nums.size()]
    if(left==nums.size()) return -1;
    return (nums[left]==target)?left:-1;
    //To insert(另一个用法)
    return left;
}

int binary_search_right_val(vector<int>& nums, int target){
    int left(0),right(nums.size());
    
    while(left<right){
        int mi = (left+right)>>1;
        if(nums[mi]==target)
            left = mi+1;
        else if(nums[mi]<target)
            left = mi+1;
        else if(target<nums[mi])
            right = mi;
    }
    //left [0,nums.size()]
    if(left==0) return -1;
    return (nums[left-1]==target)?left-1:-1;
}
