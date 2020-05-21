#include"../leetcode.h"

class solution{
public:
    int prodp(int k){
        int table[100];//k<=100
        table[0]=0;
        for(int i=1;i<=k;i++){
            table[i]=table[i-1]+1;
            for(int j=2;j<=i;j++){
                table[i]=max(table[i],table[i-j]*(i-j+1));
            }
        }
        return table[k];
    }
};