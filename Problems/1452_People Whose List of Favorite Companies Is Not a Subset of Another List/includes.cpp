#include"../leetcode.h"

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        //include()
        vector<int> result;
        for(auto &tem:favoriteCompanies)
            sort(tem.begin(),tem.end());
        
        for(int i=0;i<favoriteCompanies.size();i++){
            bool f = false;;
            for(int j=0;j<favoriteCompanies.size();j++){
                if(j!=i)
                    f = includes(favoriteCompanies[j].begin(),favoriteCompanies[j].end(),favoriteCompanies[i].begin(),favoriteCompanies[i].end());
                if(f)
                    break;
            }
            if(!f)
                result.push_back(i);
        }
        return result;
    }
};