#include"leetcode.h"

class Solution {
public:
    string convert(string s, int numRows);
};

string Solution::convert(string s, int numRows){
    if(s.empty()) return"";
    int col = min(numRows,(int)s.size());//--讨论情况
    if(col==1) return s;
    vector<string> strs(col,"");
    bool down=false;//----------------flag to declare the direction
    int num=0;
    for(int i=0;i<s.size();i++){
        if(i%(col-1)==0)//------------divide by zero
            down=!down;
        if(down){
            strs[num].push_back(s[i]);
            num++;
        }
        else{
            strs[num].push_back(s[i]);
            num--;
        }
    }
    string result;
    for(int i=0;i<strs.size();i++){
        result+=strs[i];
    }
    return result;
}