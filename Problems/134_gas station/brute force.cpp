#include"../leetcode.h"
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        for(int i=0;i<gas.size();i++){
            bool can = true;
            int n = gas.size();
            int m=gas[i]-cost[i];
            int j=(i+1)%n;
            while(j!=i){
                if(m<0){
                    can = false;
                    break;
                }
                m += gas[j]-cost[j];
                j = (j+1)%n;
            }
            if(m<0)
                can =false;
            if(can)
                return i;
        }
        return -1;
    }
};