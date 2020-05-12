#include"../leetcode.h"

class Solution {
public:
    int reverse(int x){
        string s=to_string(abs(x));
        string r;
        if(x==0) return 0;
        if(x<0)
            r+="-";
        stack<char> st;
        for(auto c:s)
            st.push(c);
        while(!st.empty()){
            r+=st.top();
            st.pop();
        }
        if(stol(r)>INT_MAX || stol(r)<INT_MIN)
            return 0;
        else
            return stoi(r);
    }
};