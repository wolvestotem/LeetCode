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
    ListNode* myremoveElements(ListNode* head, int val);
    ListNode* removeElements(ListNode* head, int val);
};

//My solution
ListNode* Solution::myremoveElements(ListNode* head, int val){
    if (head == nullptr) return(nullptr);
    ListNode *slow;
    ListNode *fast;
    slow = head;
    fast = head->next;
    
    while(fast != nullptr){
        if (fast->val == val){
            fast = fast->next;
            slow->next = fast;
        }
        else{
            slow = slow->next;
            fast = fast->next;
        }
    }
    if (head->val == val){
        head = head->next;
    }
    return (head);
}

//Discussion solution
ListNode* Solution::removeElements(ListNode* head, int val){
    
    //create dummy before head
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *header = &dummy;
    ListNode *slow = &dummy;
    ListNode *fast = head;
    
    while(fast){
        if (fast->val == val){
            fast = fast->next;
            slow->next = fast;
        }
        else{
            slow = slow->next;
            fast = fast->next;
        }
    }
    head = header->next;
    return(head);
}

