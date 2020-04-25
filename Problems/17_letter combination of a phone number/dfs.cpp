#include"../leetcode.h"

class Solution {
    vector<string> result;
    unordered_map<char,string> m={
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"},
    };
public:
    vector<string> letterCombinations(string digits);
    void dfs(string digits,int index,string path);
};

void Solution::dfs(string digits,int index,string path){
    if(index==digits.size()){
        result.push_back(path);
        return;
    }
    for(auto i:m[digits[index]]){
        dfs(digits,index+1,path+i);
    }
}

vector<string> Solution::letterCombinations(string digits){
    if(digits.empty()) return result;
    string path;
    dfs(digits,0,path);
    return result;
}