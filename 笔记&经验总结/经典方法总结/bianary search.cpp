#include"leetcode.h"

int binary_search(vector<int> nums,int lo,int hi,int target){
    while(lo<hi){
        int mi = (lo+hi)>>1;
        (target<nums[mi])?hi=mi:lo=mi+1;
    }
    return binary_search(nums,lo,hi,target)?--lo:lo;
}