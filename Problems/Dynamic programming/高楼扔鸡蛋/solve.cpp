#include"../leetcode.h"

class Solution{
    int dp(int N, int k);

int Solution::dp(int N, int k){
    //剩余楼层N, 剩余鸡蛋k
    if(N==0) return 0;
    if(k==1) return N;
    vector<vector<int>> table(N+1,tem);

    //N==0时 0步
    for(int i=0;i<=k;i++){
        table[0][i] = 0;
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=k; j++){
            if(j==1)
                table[i][j] = j;
            else{
                for(int l=1; l<=i; l++){
                    table[i][j] = min(table[i][j], max(table[l-1][j-1],table[i-l][j]));
                }
            }
        }
    }
    return table[N][k];
}