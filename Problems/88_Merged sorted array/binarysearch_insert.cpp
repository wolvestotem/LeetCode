#include"../leetcode.h"
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
    int search(int lo, int hi, vector<int>& nums, int target);
};

int Solution::search(int lo, int hi, vector<int>& nums, int target){
    int mi;
    while(lo<hi){
        mi = (lo + hi)>>1;
        (target<nums[mi])?hi = mi:lo = mi+1;//Attention!!!---------target<nums[mi]
    }
    return(lo-1);           //Attention!!!------lo-1 points to less or equal to target
}

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int lo = 0;int position = 0;
    nums1.erase(nums1.begin()+m,nums1.end());
    for (int i = 0; i<n; i++){
        position = search(lo,nums1.size(),nums1,nums2[i]);
        nums1.insert(nums1.begin()+position+1,nums2[i]); //insert  iterator位置
        lo = position;
    }
}