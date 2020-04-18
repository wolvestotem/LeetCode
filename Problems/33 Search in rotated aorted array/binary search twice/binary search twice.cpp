#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target);
    int rotationIndex(vector<int>& nums);
    int bsearch(int lo, int hi, vector<int> nums, int target);
};
int Solution::rotationIndex(vector<int>& nums) {
    int lo = 0;
    int hi = nums.size()-1;
    int mi;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        (nums[mi] < nums[hi]) ? hi = mi : lo = mi + 1;
    }
    if (lo == 0 && nums[lo] < nums[lo + 1])return(-1);
    return(--lo);
}

int Solution::search(vector<int>& nums, int target) {
    if (nums.empty()) return(-1);
    int result;
    if (nums.size() == 1)return(nums[0] == target ? 0 : -1);
    int r = rotationIndex(nums);//max rank
    if (r == -1)
        return bsearch(0, nums.size(), nums, target);
    if (target >= nums[0])
        result = bsearch(0, r, nums, target);
    else if (target <= nums[nums.size() - 1])
        result = bsearch(r, nums.size(), nums, target);
    else
        return(-1);
    return(result);
}

int Solution::bsearch(int lo, int hi, vector<int> nums, int target) {
    int mi;
    int ll = lo, hh = hi;
    while (lo < hi) {
        mi = (hi + lo) >> 1;
        (target < nums[mi]) ? hi = mi : lo = mi + 1;
    }
    return(binary_search(nums.begin() + ll, nums.begin() + hh, target) ? --lo : -1);
}


int main() {
    Solution s;
    int n,target;
    vector<int> nums;
    cin >> n >> target;
    while (n--) {
        int i;
        cin >> i;
        nums.push_back(i);
    }
    int result = s.search(nums, target);
    int r = s.rotationIndex(nums);
    cout << r  << endl;
}