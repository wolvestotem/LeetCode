#include"../leetcode.h"

string pre;
class Solution {
    
public:
    string customSortString(string S, string T);
    static bool myfunction(const char a, const char b){//必须static 
        return pre.find(a)<pre.find(b);
    }
};

string Solution::customSortString(string S, string T){
    pre=S;
    sort(T.begin(),T.end(),myfunction);//myfunction 不能是non-static member function
    return(T);        
}


