#include"../leetcode.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s);
};

int Solution::lengthOfLongestSubstring(string s){
    if(s.empty())return 0;
    int max=-1;
    string sub;
    int lo=0;
    while(true){
        sub=s.substr(lo,1);
        int curr=lo+1;
        while(sub.find(s[curr])==string::npos && curr<s.size()){
            sub.push_back(s[curr]);
            curr++;
        }
        if(sub.size()>max)
            max=sub.size();
        lo=lo+sub.find(s[curr])+1;
        if(curr>=s.size()-1)
            break;
    }
    return max;
}