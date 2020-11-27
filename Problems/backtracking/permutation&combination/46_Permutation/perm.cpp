#include"../leetcode.h"

class Solution {
    vector<vector<int>> res;
public:
    void recur(vector<int>& nums, int n, vector<int>& path, unordered_map<int,int>& m){
        if(n==0){
            res.push_back(path);
            return;
        }
        for(int i:nums){
            if(m[i]==0){//用map计量次数，不能使用count/find，最好就是初始化后用value计量
                m[i]++;
                path.push_back(i);
                recur(nums,n-1,path,m);
                m[i]--;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
            return res;
        vector<int> path;
        unordered_map<int,int> m;
        for(int i:nums)
            m[i]=0;
        recur(nums,nums.size(),path,m);
        return res;
    }
};