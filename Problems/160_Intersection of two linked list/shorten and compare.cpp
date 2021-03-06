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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
    int len(ListNode *ms);
};

int Solution::len(ListNode *ms){
    int length=0;
    while(ms != nullptr){
        length++;
        ms = ms->next;
    }
    return(length);
}

ListNode* Solution::getIntersectionNode(ListNode *headA, ListNode *headB){//测试一下
    if(headA == nullptr) return(nullptr);
    if (headB == nullptr) return(nullptr);
    int lenA = len(headA);
    int lenB = len(headB);
    int minus = lenA-lenB;
    ListNode *intersection = nullptr;
    
    //length to be the same
    while(minus){
        if (minus<0){
            headB = headB->next;
            minus++;
        }
        else{
            headA = headA->next;
            minus--;
        }
    }
    
    //compare same length
    while(headA && headB){
        if (headA == headB && !intersection){
            intersection = headA;
            headA = headA->next;
            headB = headB->next;
        }
        else if(headA !=headB){
            intersection = nullptr;
            headA = headA->next;
            headB = headB->next;
        }
        else{
            headA = headA->next;
            headB = headB->next;
        }
    }
    return(intersection);
}