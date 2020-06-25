#include"../leetcode.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength = 0;
        if(s.size()==0) return 0;
        int left = 0;
        unordered_set<char> ss;
        for(int i=0;i<s.size();i++){
            while(ss.find(s[i])!=ss.end()){
                ss.erase(s[left]);
                left++;
            }
            maxlength = max(maxlength,i-left+1);
            ss.insert(s[i]);
        }
        return maxlength;
    }
};