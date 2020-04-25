#include"../leetcode.h"

class Solution {
public:
    string longestPalindrome(string s);
};

string Solution::longestPalindrome(string s){
    if(s.empty()) return"";
    int len=0;
    string result;
    bool table[1000][1000]={false};
    for(int j=0;j<s.size();j++){
        for(int i=j;i>=0;i--){
            if(i==j)
                table[i][j]=true;
            if(j==i+1)
                table[i][j]=(s[i]==s[j]);
            if(j>i+1)
                table[i][j]=table[i+1][j-1] && (s[i]==s[j]);
            if(table[i][j] && j-i+1>len){
                len=j-i+1;
                result=s.substr(i,j-i+1);
            }
        }
    }
    return result;
    
}