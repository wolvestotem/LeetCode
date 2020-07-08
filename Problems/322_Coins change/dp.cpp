#include"../leetcode.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty()) return -1;
        vector<int> table(amount+1,INT_MAX);
        table[0]=0;
        for(int i=1;i<=amount;i++){
            int min_ = INT_MAX;
            for(auto c:coins){
                if(i-c>=0){
                    min_ = min(min_, table[i-c]);
                }
            }
            if(min_==INT_MAX)
                table[i]=INT_MAX;
            else
                table[i] = min_+1;
        }
        return (table[amount]==INT_MAX)?-1:table[amount];
    }
};