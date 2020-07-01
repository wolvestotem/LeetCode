#include"../leetcode.h"
class Solution {
public:
    vector<vector<int>> mythreeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty()) return result;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        sort(nums.begin(),nums.end());
        nums.resize(distance(nums.begin(),unique(nums.begin(),nums.end())));
        for(int i=0;i<nums.size();i++){

            m[nums[i]]--;
            if(m[nums[i]]==0)
                m.erase(nums[i]);
            for(int j=i;j<nums.size();j++){
                if(m.find(nums[j])==m.end())
                    continue;
                int c = -nums[i]-nums[j];
                if(c<nums[j])
                    continue;
                if(c==nums[j]&&m[c]>1){
                    result.push_back({nums[i],nums[j],c});
                }
                else if(c==nums[j]&&m[c]<=1){
                    continue;
                }
                else if(m.find(c)!=m.end()){
                    result.push_back({nums[i],nums[j],c});
                }
            }
        }
        return result;
    }
};