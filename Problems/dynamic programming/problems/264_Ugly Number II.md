## 题目

264. Ugly Number II

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note:  

    1 is typically treated as an ugly number.
    n does not exceed 1690.


## 题解

一种朴素的思想就是使用dp，因为可以观察到table[i]是由之前的某个数乘以{2,3,5}得到的，所以多阶dp遍历之前的table和choice，得到最小的为table[i]的值

```C++
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> table(n+1,INT_MAX);
        table[1]=1;
        vector<int> choices{2,3,5};
        
        for(int i=2;i<=n;i++){
            for(int c:choices){
                for(int j=i-1;j>=1;j--){
                    if(table[j]*c<=table[i-1])
                        break;
                        
                    table[i] = min(table[i],table[j]*c);
                }
            }
        }
        return table[n];
    }
};
```

## Discussion

我的方法太麻烦了，很容易看到有大量的重复计算，很多数多次进行乘choice。很自然的我们希望能不仅记录table，还记录乘choice的结果，因为大小顺序很重要，我们记录在heap/set中，

```C++
int nthUglyNumber(int n){
    vector<int> table(n+1);
    vector<int> choice{2,3,5};
    table[0]=1;
    set<long long> s;
    s.insert(1);
    for(int i=1;i<=n;i++){
        long long tem = *(s.begin());
        s.erase(s.begin());
        table[i] = tem;
        for(int c:choice){
            s.insert(tem*c);
        }
    }
    return table[n];
}
```

还有一种完全想不到的方法，利用i2,i3,i5作为choice下标，`table[i] = min(min(table[i2]*2, table[i3]*3),table[i5]*5)`,之后更新i2,i3,i5，还没有重复问题。

```C++
int nthUglyNumber(int n){
    int i2=0;
    int i3=0;
    int i5=0;
    vector<int> table(n);
    table[0]=1;
    for(int i=1;i<n;i++){
        table[i] = min(min(table[i2]*2, table[i3]*3),table[i5]*5);
        if(table[i]==table[i2]*2) i2++;
        if(table[i]==table[i3]*3) i3++;
        if(table[i]==table[i5]*5) i5++;
    }
    return table[n-1];
}
```