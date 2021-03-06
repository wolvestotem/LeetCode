#include"../leetcode.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       if (s.size() <= 1) return s.size();
        int start =0;
        int maxlen = 0;
       vector<int> map(128,0);
        for(int end = 0; end<s.size();end++){
            char insert = s[end];
            map[insert]++;
            while(map[s[end]] > 1){
                char remove = s[start];
                map[remove]--;                                   
                start++;                
            }

            maxlen = max(maxlen,end-start+1);
        }
        return maxlen;
    }
};