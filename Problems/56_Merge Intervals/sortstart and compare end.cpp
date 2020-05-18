#include"../leetcode.h"


bool com(const vector<int> a, const vector<int> b){
    return a[0]<b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.empty()) return result;
        //sort(intervals.begin(),intervals.end(),com);
        sort(intervals.begin(),intervals.end());

        //minimum start and maximum end
        for(int i=0;i<intervals.size();i++){
            int j;
            int end = intervals[i][1];//讨论时候应该注意end的更新,确保max end
            for(j=i+1;j<intervals.size();j++){
                if(intervals[j][0]<=end)//只要比end小的start time都合并
                    end = max(end,intervals[j][1]);
                else 
                    break;
            }
            j--;
            result.push_back(vector<int>{intervals[i][0],end});//end
            i=j;
        }
        return result;
    }
};