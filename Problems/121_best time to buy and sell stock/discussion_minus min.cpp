#include"../leetcode.h"

class Solution {
public:
    int maxProfit(vector<int>& prices);
    int mymaxProfit(vector<int>& prices);
};


int Solution::maxProfit(vector<int>& prices){
    if(prices.size()<2)return(0);
    int profit=0;
    int min = prices[0];
    int size = prices.size();
    for(int i = 1; i<size; i++){
        profit = (prices[i]-min>profit)?(prices[i]-min):profit;
        min = (prices[i]>min)?min:prices[i];
    }
    return(profit);
}