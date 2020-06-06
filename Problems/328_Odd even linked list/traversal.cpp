#include"../leetcode.h"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *odd = new ListNode(1);
        ListNode *even = new ListNode(2);
        ListNode *ceven(even);
        ListNode *curr(head);
        int order = 1;
        while(curr){
            if(order%2==1){
                odd->next = curr;
                curr = curr->next;
                odd = odd->next;
                order++;
            }
            else{
                even->next = curr;
                curr = curr->next;
                even = even->next;
                order++;
            }
        }
        odd->next = ceven->next;
        even->next = nullptr;
        return head;
    }
};