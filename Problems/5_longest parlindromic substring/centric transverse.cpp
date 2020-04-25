#include"../leetcode.h"


class Solution {
public:
    string centriclongestPalindrome(string s);
};

string Solution::centriclongestPalindrome(string s){
    if(s.empty()) return"";
    if(s.size()==1) return s;
    string result;
    for(int i=0;i<s.size()-1;i++){
        int j;
        for(j=0;i-j>=0 && i+j<s.size();j++){
            if(s[i-j]!=s[i+j])
                break;
        }
        if(result.size()<2*j-1)
            result=s.substr(i-j+1,2*j-1);
        for(j=0;i-j>=0 && i+j+1<s.size();j++){
            if(s[i-j]!=s[i+j+1])
                break;
        }
        if(result.size()<2*j)
            result=s.substr(i-j+1,2*j);
    }
    return result;
}
