#include"../leetcode.h"

class Solution {
public:
    string decodeString(string s);
};

string Solution::decodeString(string s){
    stack<char> ops;
    string result;
    
    for (int i=0; i<s.size(); i++){
        if(s[i] == ']'){
            string mi;
            while(ops.top()!='['){
                mi.insert(mi.begin(),ops.top());
                ops.pop();
            }
            ops.pop();
            int n = ops.top()-'0';
            ops.pop();
            while(n){
                n--;
                result += mi;
            }
        }
        else
            ops.push(s[i]);
    }
    return(result);
}