#include"../leetcode.h"

class Solution {
    vector<string> result;
public:
    vector<string> generateParenthesis(int n);
    void recur(int m, stack<int> s,string str);
};

void Solution::recur(int m, stack<int> s,string str){
    if(m==0)
        result.push_back(str);
    else{
        if(s.empty()){
            s.push(1);
            str+="(";
            recur(m-1,s,str);
        }
        else if(s.size()==m){
            s.pop();
            str+=")";
            recur(m-1,s,str);
        }
        else{
            s.push(1);
            recur(m-1,s,str+"(");
            s.pop();
            s.pop();
            recur(m-1,s,str+")");
        }
    }
}

vector<string> Solution::generateParenthesis(int n){
    stack<int> s;
    string r="";
    recur(2*n,s,r);
    return result;
}