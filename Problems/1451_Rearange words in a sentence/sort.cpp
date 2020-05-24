#include"../leetcode.h"

bool comparison(const string& a, const string& b){
    return a.size()<b.size();
}

class Solution {
public:
    string arrangeWords(string text) {
        if(text.size()==0) return "";
        vector<pair<string,int>> word;
        text[0] = tolower(text[0]);

        stringstream ss(text);
        string w;
        int rank(0);
        while(ss>>w) word.emplace_back(w,rank++);
        
        //costum sort
        sort(word.begin(),word.end(),[](const auto &a, const auto &b){return a.first.size()<b.first.size() || (a.first.size()==b.first.size() && a.second<b.second);});
        string result;
        for(int i=0;i<word.size();i++){
            result = result+word[i].first;
            if(i!=word.size()-1)
                result += " ";
        }
        result[0] = toupper(result[0]);
        return result;
    }
};