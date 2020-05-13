#include"../leetcode.h"

class Solution {
    vector<string> result;
public:
    vector<string> generateParenthesis(int n);
    void recur(int m, int open, int close ,string str,int n);
};

void Solution::recur(int m, int open, int close ,string str,int n){
    if(m==0){
        result.push_back(str);
        return;
    }
    else{
        if(open<n){
            recur(m-1,open+1,close,str+"(",n);
        }
        if(close<open){
            recur(m-1,open,close+1,str+")",n);
        }
    }
}


vector<string> Solution::generateParenthesis(int n){
    int open=0;
    int close=0;
    string r="";
    recur(2*n,open,close,r,n);
    return result;
}