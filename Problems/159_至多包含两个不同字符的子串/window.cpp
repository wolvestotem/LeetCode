#include"../leetcode.h"

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.size()==0) return 0;
        int maxlength = 0;
        int length(0);
        int right(0),left(0);
        unordered_map<char,int> dic;
        
        while(right<s.size()){
            dic[s[right]]++;
            length++;
            while(dic.size()>2){
                dic[s[left]]--;
                length--;
                if(dic[s[left]]==0)
                    dic.erase(s[left]);
                left++;
            }
            
            maxlength = max(maxlength, length);
            right++;
        }
        return maxlength;
    }
};