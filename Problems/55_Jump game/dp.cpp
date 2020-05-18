#include"../leetcode.h"

class Solution {
public:
    //OPT(n)=nums[n]是否从零可达
    bool mycanJump(vector<int>& nums) {
        if(nums.empty()) return false;
        if(nums.size()==1) return true;
        int n = nums.size();
        vector<bool> table(n,false);
        table[0] = true;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(!table[i])
                    table[i] = table[i] || (table[j] && (j+nums[j]>=i));
            }
        }
        return table[n-1];
    }
    
    //OPT[n]=是否可从nums[n]达到final
    bool sol_canJump(vector<int>& nums){
        if(nums.empty()) return false;
        if(nums.size()==1) return true;
        int n = nums.size();
        vector<bool> table(n,false);
        table[n-1]=true;
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=nums[i]&&(i+j)<n;j++){
                if(table[i+j])
                    table[i] = true;
            }
        }
        return table[0];
    }
};