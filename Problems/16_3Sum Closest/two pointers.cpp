#include"../leetcode.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        int result = 40000;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int j(i+1),k(nums.size()-1);
            while(j<k){
                if(j>i+1 && nums[j]==nums[j-1]){
                    j++;
                    continue;
                }
                if(k<nums.size()-1 && nums[k]==nums[k+1]){
                    k--;
                    continue;
                }
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==target){
                    return target;
                }
                if(sum<target){
                    j++;
                    result = (abs(result-target)>abs(sum-target))?sum:result;
                }
                else{
                    k--;
                    result = (abs(result-target)>abs(sum-target))?sum:result;
                }
            }
        }
        return result;
    }
};