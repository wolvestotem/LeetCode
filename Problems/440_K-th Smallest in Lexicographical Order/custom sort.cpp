#include"../leetcode.h"

class Solution {
public:
    static bool comparison(const int a, const int b){
        string i = to_string(a);
        string j = to_string(b);
        int k = 0;
        while(k<i.size() && k<j.size()){
            if(i[k]==j[k]){
                k++;
            }
            else{
                return i[k]<j[k];
            }
        }
        return i.size()<j.size();
    }
    int findKthNumber(int n, int k) {
        vector<int> dic;
        for(int i=1;i<=n;i++){
            dic.push_back(i);
        }
        sort(dic.begin(),dic.end(),comparison);
        return dic[k-1];
    }
};