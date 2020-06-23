#include"../leetcode.h"

class Solution {
    int mod =1337;
public:
    long long pow(int a, int n){
        if(n==0) return 1;
        long long y = pow(a,n/2)%mod;
        return (n%2)?(y*y*a)%mod:(y*y)%mod;
    }
    
    int superPow(int a, vector<int>& b) {

        if(b.empty()) return 1;
        a = a%mod;
        int ten=a;
        int one;
        long long res=1;
        while(!b.empty()){
            one = b.back();
            b.pop_back();
            res = (res*pow(ten,one))%mod;
            ten = pow(ten,10);
        }
        return res;
    }
};