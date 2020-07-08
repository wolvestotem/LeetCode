#include"../leetcode.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        if(nums.empty()) return {};
        vector<int> front(nums.size()+2,1);
        vector<int> back(nums.size()+2,1);
        int cal=1;
        for(int i=0;i<nums.size();i++){
            cal = cal*nums[i];
            front[i+1] = cal;
        }
        cal=1;
        for(int i=nums.size()-1;i>=0;i--){
            cal *= nums[i];
            back[i+1] = cal;
        }
        for(int i=0;i<nums.size();i++){
            res[i] = front[i]*back[i+2];
        }
        return res;
    }
};