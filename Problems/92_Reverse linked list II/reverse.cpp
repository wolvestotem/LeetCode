#include"../leetcode.h"

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        ListNode *st;
        ListNode *pre,*curr,*fu;
        if(!head || !head->next) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* now(dummy);
        int originm = m;
        while(--m){
            now = now->next;
        }
        curr = now->next;
        fu = curr->next;
        pre = nullptr;
        st = curr;
        int step=n-originm+1;
        while(step--){
            curr->next = pre;
            pre = curr;
            curr = fu;
            if(curr)
                fu = curr->next;
        }
        now->next = pre;
        st->next = curr;
        return dummy->next;
    }
    
};