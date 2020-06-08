#include"../leetcode.h"
class Solution{
    double iter(double x, long long n){
        double result=1;
        double order = x;
        while(n){
            if(n%2){
                result *= order;
            }
            order = order*order;
            n = n/2;
        }
        return result;
    }
    
    double myPow(double x, int n){
        if(n==0) return 1;
        if(x==0) return 0;
        long long N = n;
        double result = (n>0)?iter(x,N):1.0/iter(x,-N);
        return result;
    }
};