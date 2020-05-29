#include"../leetcode.h"
class Solution{
    ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2){
        if(!l1 || !l2)
            return (l1)?l1:l2;
        ListNode* pre = new ListNode(0);
        ListNode* curr(pre);
        while(l1 && l2){
            curr->next = (l1->val < l2->val)?l1:l2;
            (l1->val < l2->val)?(l1=l1->next):(l2=l2->next);
            curr = curr->next;
        }
        curr->next = (l1)?l1:l2;
        return pre->next;
    }
};