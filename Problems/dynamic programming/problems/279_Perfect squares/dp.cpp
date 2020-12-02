#include"../leetcode.h"

class Solution {
public:
    int numSquares(int n) {
        int num = 1;
        vector<int> choice;
        while(num*num<=n){
            choice.push_back(num*num);
            num++;
        }
        vector<int> table(n+1,INT_MAX);
        table[0]=0;
        for(int i=1;i<=n;i++){
            for(auto c:choice){
                if(i-c>=0){
                    table[i] = min(table[i], table[i-c]+1);
                }
                else
                    break;
            }
        }
        return table[n];
    }
};