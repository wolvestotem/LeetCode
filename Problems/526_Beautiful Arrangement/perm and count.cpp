#include"../leetcode.h"

class Solution {
    int count=0;
public:
    void recur(vector<int>& nums, int curr){
        if(curr==nums.size()-1){
            if(nums[curr]%(curr+1)&&(curr+1)%nums[curr])
                return;
            else{
                count++;
                return;
            }
        }
        
        for(int i=curr;i<nums.size();i++){
            if(nums[i]%(curr+1)&&(curr+1)%(nums[i]))
                continue;
            swap(nums[curr],nums[i]);
            recur(nums,curr+1);
            swap(nums[curr],nums[i]);
        }
    }
    
    int countArrangement(int N) {
        vector<int> nums;
        for(int i=1;i<=N;i++){
            nums.push_back(i);
        }
        int curr=0;
        recur(nums,curr);
        return count;
    }
};