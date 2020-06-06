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
    ListNode* reverse(ListNode *head){
        if(!head || !head->next) return head;
        ListNode *pre(nullptr), *curr(head);
        ListNode *fu(head->next);
        while(fu){
            curr->next = pre;
            pre = curr;
            curr = fu;
            fu = curr->next;
        }
        curr->next = pre;
        return curr;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;//base case
        ListNode *fa(head->next), *sl(head);
        while(fa && fa->next){
            fa = fa->next->next;
            sl = sl->next;
        }
        ListNode *right(sl->next);
        sl->next = nullptr;
        right = reverse(right);
        while(head && right){
            if(head->val != right->val)
                return false;
            head = head->next;//pointer next
            right = right->next;
        }
        return true;
    }
};