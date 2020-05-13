#include"./leetcode.h"

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode *fir{pre},*sec(pre);
        // ListNode* sec(pre);
        
        while(n--){
            fir = fir->next;
        }
        while(fir->next){
            fir = fir->next;
            sec =sec->next;
        }
        sec->next = sec->next->next;
        // delete pre;
        return pre->next;
    }
};