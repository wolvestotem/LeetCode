#include"../leetcode.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums);
};

vector<vector<int>> Solution::threeSum(vector<int>& nums){
    sort(nums.begin(), nums.end());//sort 使用
    int len = nums.size();
    if(len<3)return {};
    vector<vector<int>> result;
    
    for(int i = 0; i<len-2; i++){//最小元素
        int a = nums[i];
        if(i>0 && nums[i-1]==a)
            continue;//duplicate
        if(a>0)
            break;//sum=positive
        
        int j = i+1;
        int k = len-1;
        while(j<k){
            int b = nums[j];
            int c = nums[k];
            int sum = a+b+c;

            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else if(sum == 0){
                while(nums[j]==b && j<k){
                    j++;
                }
                while(nums[k]==c && j<k){
                    k--;
                }
                result.push_back({a,b,c});
            }
        }
    }
    return(result);
}