#include"../leetcode.h"

class Solution {
public:
    int myAtoi(string str);

};

int Solution::myAtoi(string str){
    if(str.empty()) return(0);
    bool valid=false;
    bool pos=true;
    long result=0;
    for(int i=0;i<str.size();i++){
        if(isspace(str[i])&&!valid) continue;
        if(str[i]!='-'&&str[i]!='+'&&!isdigit(str[i])&&!valid)
            return 0;
        if(valid&&!isdigit(str[i]))
            break;
        if(str[i]=='-'&&!valid){
            valid=true;
            pos=false;
        }
        if(str[i]=='+'&&!valid){
            valid=true;
        }
        
        if(isdigit(str[i])){
            result=result*10+str[i]-'0';
            valid=true;
            if(result>INT_MAX)
                break;
        }
    }
    if(!pos)
        result=-result;
    if(result>INT_MAX)
        return INT_MAX;
    if(result<INT_MIN)
        return INT_MIN;
    return (int)result;
}