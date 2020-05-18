#include"../leetcode.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int index = 0;
        while(index<=right){
            switch(nums[index]){
                case(0):
                    swap(nums[left++],nums[index++]);
                    break;
                case(1):
                    index++;
                    break;
                case(2):
                    swap(nums[index],nums[right--]);
                    break;
            }
        }
        
    }
};