#include"../leetcode.h"

int maxArea(vector<int>& height){
    int start(0),end(height.size()-1);
    int water(0);
    while(start<end){
        water = max(water,(start-end)*min(height[start],height[end]));
        while(height[start]<=height[end] && start<end){
            
            water = max(water,(end-start)*min(height[start],height[end]));
            start++;
        }
        while(height[start]>height[end] && start<end){
            
            water = max(water,(end-start)*min(height[start],height[end]));
            end--;
        }
    }
    return water;
}