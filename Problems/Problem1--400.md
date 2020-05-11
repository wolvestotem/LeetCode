Leetcode Problems #1--#400
============

#2 Add two number(Linked list)
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

#91 Decode ways
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