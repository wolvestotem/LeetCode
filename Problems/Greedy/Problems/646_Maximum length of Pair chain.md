## 题目

646. Maximum Length of Pair Chain
Medium

You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:

Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]


## 题解

经典排课问题，可以对结束时间排序，遍历取符合时间要求的集合

```C++
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size()==1) return 1;
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){return *(a.end()-1)<*(b.end()-1);});
        
        int count=0;
        int last = pairs[0][0]-1;
        for(auto p:pairs){
            if(p[0]>last){
                count++;
                last = p[1];
            }
        }
        return count;
    }
};
```