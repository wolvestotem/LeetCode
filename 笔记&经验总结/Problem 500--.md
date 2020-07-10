Leetcode Problems #500--
============

### 1143 Longest common subsequence/substring

- subsequence
使用经典dp方法，需要注意的是初始化过程。
根据递推式，写出base case
`if(s1[i]==s2[j]) OPT[i][j] = OPT[i-1][j-1]+1`，所以需要维护左边界和上边界。我最开始用`s1[0]?=s2[j];s1[i]?=s2[0]`作为初始化，是错误的，因为还有递推关系`if(s1[i]!=s2[j]) OPT[i][j] = max(OPT[i-1][j],OPT[i][j-1])`**不等不一定为零**。
可以用更大的table，但是要注意`table index`和`string index`不等

- subsequence result
回溯时（选择列表，当前路径，终止条件），应该注意边界终止条件和满足逻辑终止条件

- substring
你应该非常清楚递推关系，据此得到base case，和返回值
substring一般是局部最优子结构，返回值需要全局遍历后得到

- substring result
回溯时应该注意边界条件和逻辑终止