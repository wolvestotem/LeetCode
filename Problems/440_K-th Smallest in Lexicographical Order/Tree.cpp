#include"../leetcode.h"

class Solution {
public:
typedef long long LL;
    int findKthNumber(int n, int k) {
        int prefix = 1;
        k--; // k记录要找的数字在prefix后的第几个
        while (k>0){
            int cnt = getCnt(n, prefix); // 当前prefix 下有多少个元素;包含prefix
            if (cnt <= k) { // 向右
                k -= cnt;
                prefix++;
            } else { // 向下
                k--;
                prefix*=10;
            }
        }
        return prefix;
    }
    int getCnt(LL n, LL prefix){
        LL cnt = 0;
        for (LL first = prefix, second = prefix+1; first<=n; first*=10, second*=10){
            cnt+= min(n + 1, second) - first;
        }
        return cnt;
    }
};