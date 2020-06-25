#include"../leetcode.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s);
};

int Solution::lengthOfLongestSubstring(string s){
    if(s.empty()) return 0;
    int right(0),left(0);
    int res(0);
    unordered_map<char,int> m;
    
    while(right<s.size()){
        
        m[s[right]]++;
        while(m[s[right]]>1){
            m[s[left]]--;
            left++;
        }
        
        right++;
        res=max(right-left,res);
    }
    return res;
}
