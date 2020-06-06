#include"../leetcode.h"

class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        if(!headA || !headB) return nullptr;
        ListNode *a(headA), *b(headB);
        int times = 0;
        while(true){
            if(headA == headB)
                return headA;

            if(!headA->next){
                headA = b;
                times++;
            }
            else
                headA = headA->next;
            if(!headB->next){
                headB = a;
                times++;
            }
            else
                headB = headB->next;
            if(times>2)
                break;
            
        }
        return nullptr;
    }
};