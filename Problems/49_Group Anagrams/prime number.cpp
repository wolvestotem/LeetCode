#include"../leetcode.h"

#define ll unsigned long long
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> alpha={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        vector<vector<string>> result;
        if(strs.empty()) return result;
        
        //
        vector<ll> pro(strs.size(),1);
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs[i].size();j++){
                pro[i] = pro[i]*alpha[strs[i][j]-'a'];
            }
        }
        
        //
        unordered_map<ll,int> m;
        for(int i=0;i<pro.size();i++){
            if(m.find(pro[i])==m.end()){
                vector<string> tem={strs[i]};
                result.push_back(tem);
                m[pro[i]] = result.size()-1;
            }
            else{
                int index = m.find(pro[i])->second;
                result[index].push_back(strs[i]);
            }
        }
        return result;
    }
};