Leetcode Problems #1--#400
============

#2 Add two number(Linked list)
-------------
一个充满细节考量的加法器。我自己使用一个时间复杂度和空间复杂度高的方法，迭代地使用加法器，并构造了一个新的Linked List序列记录结果。

细节：

需要一个全局进位计数器变量，**加法器运行截止至 l1,l2,进位都为空时**，之前犯错误l1,l2其一为空就停止，实际还应该考虑进位对飞空list影响。**对空指针数值和递归使用都需要分类讨论**

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    int add=0;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2 && !add)//正确的截止条件---全部计算结束时
            return nullptr;
        int a,b;
        a = (l1)?l1->val:0;//空指针数值讨论
        b = (l2)?l2->val:0;
        int sum = (a+b+add);
        add = sum/10;
        ListNode* head;
        if(l1 && l2)
            head = new ListNode(sum%10,addTwoNumbers(l1->next,l2->next));
        else{
            if(!l1 && !l2)//空指针递归使用讨论
                head = new ListNode(sum%10,addTwoNumbers(nullptr,nullptr));
            else
                head = (l1)?new ListNode(sum%10,addTwoNumbers(l1->next,nullptr)):new ListNode(sum%10,addTwoNumbers(nullptr,l2->next));
        }
        return head;
    }
};
```

#7 Reverse integer
------------------------

+ 只能32位integer

关键点在于INT_MAX比INT_MIN绝对值小1，所以不能对称的判断，而要分正负讨论

另外对负数求余还是负数，可以直接求余入队

+ 可以使用long

使用string可以更加方便的换顺序，最后加以验证

#11 Container with most water
-------------------

最值问题，但是并不是用dp解决，思考时候限于dp太多

brute force其实就比较好，T(n)=O(n2)，比较简单

Discussion给出two pointers 解法。数组经常用左右指针，linked list经常用快慢指针。


#19 Remove Nth node from the end
-------------------

本问题有三点值得注意：

+ 是list的问题，可以想到快慢指针，利用指针步数度量
+ 利用pre指针更好解决list问题，返回pre->next，而不是head，防止head被影响
+ 更好的初始化策略

```C++
// Initialization
ListNode *fir(pre), *sec(pre);
ListNode *fir{pre};
```

#22 Generate parentheses
------------------

本题关键点：backtracking，类似于permutation，或者BFS+剪枝。利用recurse充分讨论每层的所有情况，直至讨论结束。设计BFS剪枝方向时候，应该想好怎么判断，本题中用open,close,显然由于stack。

```C++
class Solution {
    vector<string> result;
public:
    vector<string> generateParenthesis(int n);
    void recur(int m, int open, int close ,string str,int n);
};

void Solution::recur(int m, int open, int close ,string str,int n){
    if(m==0){//结束
        result.push_back(str);
        return;
    }
    else{
        if(open<n){
            recur(m-1,open+1,close,str+"(",n);//函数参数可以直接计算
        }
        if(close<open){
            recur(m-1,open,close+1,str+")",n);
        }
    }
}
vector<string> Solution::generateParenthesis(int n){
    int open=0;
    int close=0;
    string r="";
    recur(2*n,open,close,r,n);
    return result;
}
```


#91 Decode ways
-----------------

经典dp问题，需要讨论s[i]是否为零。

s[i]为零，只能table[i-2]后者return 0; s[i]不为零，讨论后两位是否能decode，分情况说明。

```C++
class Solution {
public:
    int numDecodings(string s);
};

int Solution::numDecodings(string s){
    
    vector<int> table(s.size()+1,1);
    //base case
    if(s[0]=='0')
        return 0;
    else
        table[1]=1;
    
    for(int i=2;i<=s.size();i++){
        if(s[i-1]!='0'){
            if(stoi(s.substr(i-2,2))<=26 && stoi(s.substr(i-2,2))>10)
                table[i] = table[i-1]+table[i-2];
            else
                table[i] = table[i-1];
        }
        else{
            if(stoi(s.substr(i-2,2))==10 || stoi(s.substr(i-2,2))==20)
                table[i] = table[i-2];
            else
                return 0;
        }
    }
    return table[s.size()];
}
```