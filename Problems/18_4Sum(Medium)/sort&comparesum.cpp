#include"../leetcode.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target);
};

vector<vector<int>> Solution::fourSum(vector<int>& nums, int target){
    int len = nums.size();
    if(len < 4) return {};
    sort(nums.begin(), nums.end());//Attention---sort is helpful
    vector<vector<int>> result;
    
    for (int i = 0; i<len-3; i++){
        int a = nums[i];
        if(a>=0 && target<0)
            //skip for positive
            break;
        if (i>0 && a == nums[i-1])continue;
        // if (nums[i] == nums[i-1] && i > 0) continue;
            //duplicate
            // continue;
        for(int j = i+1; j<len-2; j++){
            int b = nums[j];
            if (a+b>=0 && target<0)
                //skip for positive
                break;
            if(nums[j-1]==b && j>i+1)
                //skip for duplicate
                continue;
            int k = j+1;
            int p = len-1;
            
            while (k<p){
                int c = nums[k];
                int d = nums[p];
                int sum = a+b+c+d;
                
                if (sum<target)
                    k+=1;
                else if(sum > target)
                    p-=1;
                else if(sum == target){
                    while(c == nums[k] && k<p){
                        k+=1;
                    }
                    while(d == nums[p] && k<p){
                        p-=1;
                    }
                    result.push_back({a,b,c,d});
                }
            }
        }
    }
    return(result);
}