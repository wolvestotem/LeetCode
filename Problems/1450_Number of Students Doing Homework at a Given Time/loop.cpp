#include"../leetcode.h"

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        if(startTime.empty()) return 0;
        int count = 0;
        for(int i=0;i<startTime.size();i++){
            if(startTime[i]<=queryTime){
                if(endTime[i]>=queryTime){
                    count++;
                }
            }
        }
        return count;
    }
};