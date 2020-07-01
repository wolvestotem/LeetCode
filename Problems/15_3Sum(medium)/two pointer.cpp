#include"../leetcode.h"

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> result;
        if(nums.empty()) return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                // i++;
                //for中结尾会++，continue不需要再++
                continue;
            }
            int j(i+1),k(nums.size()-1);
            while(j<k){

                if(j>i+1 && nums[j]==nums[j-1]){
                    j++;//while没有自己的++，需要自增
                    continue;
                }
                if(k<nums.size()-1 && nums[k]==nums[k+1]){
                    k--;
                    continue;
                }
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    result.push_back({nums[i],nums[j],nums[k]});
                    j++;//注意更新index
                    k--;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return result;
    }
};