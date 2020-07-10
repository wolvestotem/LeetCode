#include"../leetcode.h"

class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size()<=1) return;
        int st(0),e(s.size()-1);
        while(st<e){
            swap(s[st],s[e]);
            st++;
            e--;
        }
    }
};