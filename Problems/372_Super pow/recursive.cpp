#include"../leetcode.h"

class Solution {
    int mod =1337;
    
public:
    long long pow(int a, int n){
        if(n==0) return 1;
        long long y = pow(a,n/2)%mod;
        return (n%2)?(y*y*a)%mod:(y*y)%mod;
    }
    
    int superPow(int a, vector<int>& b){
        if(b.empty()) return 1;
        int result=1;
        a = a%mod;
        int one = b.back();
        b.pop_back();
        result = (result*pow(a,one))%mod;
        int rest = superPow(a,b);
        result = (result*pow(rest,10))%mod;
        return result;
    }
};