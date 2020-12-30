
35. Search Insert Position
Easy

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
```C++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target){
        int left=0;
        int right=nums.size();
        int mid;
        while(left<right){
            mid = left+((right-left)>>1);
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
};
```