#include"../leetcode.h"

class Solution {
public:
    int did(long a, long b){
        if(a<b)
            return 0;
        long c=b;
        int time=1;
        while(a>=c+c){
            c=c<<1;
            time=time<<1;
        }
        // c = c>>1;
        // time=time>>1;
        time=time+did(a-c,b);
        return time;
    }
    
    int divide(int dividend, int divisor) {
        if(divisor==1) return dividend;
        if(divisor==-1){
            if(dividend>INT_MIN) return -dividend;
            return INT_MAX;
        }
        if(divisor==0) return INT_MAX;
        
        long a=dividend;
        long b = divisor;
        int sign = 1;
        if(a>0&&b<0 || a<0&&b>0)
            sign=-1;
        a = (a>0)?a:-a;
        b = (b>0)?b:-b;
        
        int result = sign*did(a,b);
        return result;
    }
};