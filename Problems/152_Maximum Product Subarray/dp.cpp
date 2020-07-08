#include"../leetcode.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<pair<int,int>> table(nums.size(), pair<int,int>(0,0));
        //<min, max>
        table[0].first = nums[0];
        table[0].second = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==0){
                table[i].first=0;
                table[i].second=0;
            }
            else if(nums[i]>0){
                table[i].second = max(nums[i],table[i-1].second*nums[i]);
                table[i].first = min(nums[i],table[i-1].first*nums[i]);
            }
            else if(nums[i]<0){
                table[i].second = max(nums[i],table[i-1].first*nums[i]);
                table[i].first = min(nums[i],table[i-1].second*nums[i]);
            }
        }
        int max_ = INT_MIN;
        for(auto p:table){
            if(p.second>max_)
                max_ = p.second;
        }
        return max_;
    }
};