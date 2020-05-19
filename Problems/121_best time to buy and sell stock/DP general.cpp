#include"../leetcode.h"

int maxProfit(vector<int>& prices){
    int n = prices.size();
    if(n==0) return 0;
    vector<vector<vector<int>>> table(n+1,vector<vector<int>>(2,vector<int>(2,0)));
    for(int i=0;i<=n;i++){
        for(int k=0;k<2;k++){
            for(int j=0;j<2;j++){
                //base case
                if(k==0 && j==0)
                    table[i][k][j]=0;
                else if(k==0 && j==1)
                    table[i][k][j]==INT_MIN;//impossible
                else if(i==0 && j==0)
                    table[i][k][j]=0;
                else if(i==0 && j==1)
                    table[i][k][j]=INT_MIN;
                
                //OPT recurse
                 else if(j==1)
                     table[i][k][j] = max(table[i-1][k][1],table[i-1][k-1][0]-prices[i-1]);
                else
                    table[i][k][j] = max(table[i-1][k][0],table[i-1][k][1]+prices[i-1]);
            }
        }
    }
    return table[n][1][0];
}