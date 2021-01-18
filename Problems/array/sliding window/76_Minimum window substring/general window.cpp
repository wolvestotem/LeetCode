#include"../leetcode.h"

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()==0 || t.size()==0)
            return "";
        string result;
        int minlength=INT_MAX;
        int left(0), right(0);
        unordered_map<char,int> mapt;
        unordered_map<char,int> maps;
        for(char c:t){
            mapt[c]++;
        }
        int valid = 0;
        int n = mapt.size();
        while(right<s.size()){
            if(mapt.count(s[right])){
                maps[s[right]]++;
                if(maps[s[right]]==mapt[s[right]]){
                    valid++;
                }
            }
            
            right++;//right右移，更新maps[]
            //[left,right)
            while(valid==n){//当valid==n时，开始左移
                int length = right-left;
                if(length<minlength){
                    minlength = length;
                    result = s.substr(left,length);//求min在收缩中求
                }
                if(mapt.count(s[left])){
                    if(maps[s[left]]==mapt[s[left]])
                        valid--;
                    maps[s[left]]--;//左移时更新maps[]
                }
                left++;
            }
        }
        return result;
    }
};