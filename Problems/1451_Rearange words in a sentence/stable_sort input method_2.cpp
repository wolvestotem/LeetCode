#include"../leetcode.h"

bool comparison(const string& a, const string& b){
    return a.size()<b.size();
}

class Solution {
public:
    string arrangeWords(string text) {
        //32
        if(text.size()==0) return "";
        vector<string> word;
        text[0] = tolower(text[0]);

        //INPUT to the vector of strings
        int start(0);
        while(text.find_first_of(" ")!=string::npos){
            int found = text.find_first_of(" ");
            text[found] = '*';
            word.push_back(text.substr(start,found-start));
            start = found+1;
        }
        word.push_back(text.substr(start));
        //END

        stable_sort(word.begin(),word.end(),[](const string &a, const string &b){return a.size()<b.size();});
        string result;
        for(int i=0;i<word.size();i++){
            result = result+word[i];
            if(i!=word.size()-1)
                result += " ";
        }
        result[0] = toupper(result[0]);
        return result;
    }
};