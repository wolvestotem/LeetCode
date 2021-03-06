class Solution {
public:
    int maxSubArray(vector<int>& nums);
};

int Solution::maxSubArray(vector<int>& nums){
    if(nums.empty())return(0);
    int max = INT_MIN; int sum = 0;
    for (int i = 0; i<nums.size(); i++){
        sum += nums[i];
        if(max<sum)
            max = sum;
        if (sum < 0)   //key point
            sum = 0;
    }
    return(max);
}