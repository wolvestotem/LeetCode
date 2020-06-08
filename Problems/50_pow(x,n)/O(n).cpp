#include"../leetcode.h"

class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        if(x==1) return 1;
        if(x==-1) return (n%2)?-1:1;
        if(n==0) return 1;
        double result=1;
        if(n>0){
            while(n){
                if(abs(result)>=abs(DBL_MAX/x))
                    return numeric_limits<double>::infinity();
                else if(result==0){
                    return result;
                }
                else{
                    result = result*x;
                }
                n--;
            }
        }
        else{
            while(n){
                if(abs(result)>=abs(DBL_MAX*x))
                    return numeric_limits<double>::infinity();
                else if(result==0){
                    return result;
                }
                else{
                    result = result/x;
                }
                n++;
            }
        }
        return result;
    }
};