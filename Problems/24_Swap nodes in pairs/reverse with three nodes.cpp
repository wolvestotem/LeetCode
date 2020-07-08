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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode *past(pre),*fir(head),*sec(head->next);
        while(sec){
            fir->next = sec->next;
            sec->next = fir;
            past->next = sec;
            past = fir;
            fir = fir->next;
            if(fir)
                sec = fir->next;
            else 
                break;
        }
        return pre->next;
    }
};