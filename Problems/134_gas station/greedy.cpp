#include"../leetcode.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int sum = 0;
        int index=0;
        int m = INT_MAX;
        int n=gas.size();
        for(int i=0;i<gas.size();i++){
            sum += gas[i]-cost[i];
            if(sum<m){
                m = sum;
                index=i;
            }
        }
        if(sum<0)
            return -1;
        else
            return (index+1)%n;
    }
};