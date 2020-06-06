#include"../leetcode.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;
        unordered_set<ListNode*> m;
        while(headA){
            m.emplace(headA);
            headA = headA->next;
        }
        while(headB){
            if(m.find(headB)!=m.end())
                return headB;
            headB = headB->next;
        }
        return nullptr;
    }

};