# 剑指Offer

### 22 链表中倒数第k个节点

应该注意的是代码的特殊输出和边界条件判定

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(!head || k<=0) return nullptr;//输入 head\k 非法
        ListNode *pre = new ListNode(0);
        pre->next = head;
        ListNode *fir(pre),*sec(pre);
        for(int i=1;i<k;i++){//输入k非法
            if(fir->next)
                fir = fir->next;
            else
                return nullptr;
        }
        while(fir->next){
            fir = fir->next;
            sec = sec->next;
        }
        return sec;
    }
};
```
