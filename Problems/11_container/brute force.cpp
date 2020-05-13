#include"../leetcode.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int water=0;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                water=max(water,(j-i)*min(height[i],height[j]));
            }
        }
        return water;
    }
};