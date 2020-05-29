#include"../leetcode.h"

bool comparison(const string& a, const string& b){
    return a.size()<b.size();
}

class Solution {
public:
    string arrangeWords(string text){
        text[0] = tolower(text[0]);
        stringstream ss(text),rs;
        string result;
        map<int,string> m;
        //map是有序的，通过key有序直接完成排序
        string word;
        while(ss>>word)
            m[word.size()] += word+" ";
        for(auto &pair:m) result += pair.second;
        //rs<<pair.seond;
        // result = rs.str();
        result.pop_back();
        result[0] = toupper(result[0]);
        return result;
    }
};