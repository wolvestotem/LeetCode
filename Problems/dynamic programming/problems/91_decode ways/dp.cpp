#include"../leetcode.h"

class Solution {
public:
    int numDecodings(string s);
};

int Solution::numDecodings(string s){
    
    vector<int> table(s.size()+1,1);
    //base case
    if(s[0]=='0')
        return 0;
    else
        table[1]=1;
    
    for(int i=2;i<=s.size();i++){
        if(s[i-1]!='0'){
            if(stoi(s.substr(i-2,2))<=26 && stoi(s.substr(i-2,2))>10)
                table[i] = table[i-1]+table[i-2];
            else
                table[i] = table[i-1];
        }
        else{
            if(stoi(s.substr(i-2,2))==10 || stoi(s.substr(i-2,2))==20)
                table[i] = table[i-2];
            else
                return 0;
        }
    }
    return table[s.size()];
}
