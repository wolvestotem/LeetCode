## 题目

713. Subarray Product Less Than K
Medium

Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.
0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.

## 题解

本题有大量需要思考的点
首先从总体思路上讲，因为避免重复乘法，所以使用dp是一种直观思路。但是我们还应该看到问题时求解一个subarray，所以还应该想到sliding window的解法。
直接暴力计算全数组乘积是不可行的，**本题中全部正数，使用log2()大量减少了结果的数值**，这是一个没有想到的常见思路！！
log2()后doule类型的比较中注意`table[mid]-table[i]<logk-1e-9`不能直接比

又因为在写的过程中注意到，如果i和j符合，i和j之间的都符合，并且table是一个单调不降的数组，所以将遍历问题变成查找问题，使用二分查找。
注意二分中的边界条件

```C++
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        int count=0;
        double logk = log2(k);
        vector<double> table(nums.size()+1,0);
        
        for(int i=0;i<nums.size();i++){
            table[i+1] = table[i]+log2(nums[i]);
        }
        
        for(int i=0;i<table.size();i++){
            // binary search
            int lo=i+1;
            int hi=table.size();
            while(lo<hi){
                int mid = (lo+hi)>>1;
                if(table[mid]-table[i]<logk-1e-9)
                    lo=mid+1;
                else
                    hi=mid;
            }
            count=count+lo-1-i;
        }
        return count;
    }
};
```

sliding window解法

需要注意count加法时机，每次加法时候左右边界开闭情况
刷新l和r

```C++
int numSubarrayProductLessThanK(vector<int>& nums, int k){
    int l=0,r=0;
    int count=0;
    long long production=1;
    while(r<nums.size()){
        production = production*nums[r];
        r++;
        while(production>=k && l<r){
            production /= nums[l];
            l++;
        }
        count+=r-l;
        
    }
    return count;
}
```