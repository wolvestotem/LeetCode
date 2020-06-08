#include"../leetcode.h"
class Solution{
    double recur(double x, long long n){
        if(n==0) return 1.0;
        double y = recur(x,n/2);
        return (n%2)?y*y*x:y*y;
    }

    double myPow(double x, int n){
        if(n==0) return 1;
        if(x==0) return 0;
        long long N = n;
        double result = (n>0)?recur(x,N):1.0/recur(x,-N);
        return result;
    }
};