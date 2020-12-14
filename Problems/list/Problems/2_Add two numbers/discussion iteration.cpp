#include"../leetcode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    int add=0;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2){
    int add=0;
    ListNode* pre = new ListNode(0);
    ListNode* curr;
    curr=pre;
    while(l1 || l2){
        int a,b;
        a = (l1)?l1->val:0;
        b = (l2)?l2->val:0;
        int sum = (a+b+add);
        curr->next = new ListNode(sum%10);
        add = sum/10;
        l1 = (l1)?l1->next:nullptr;
        l2 = (l2)?l2->next:nullptr;
        curr = curr->next;
    }
    if(add) 
        curr->next = new ListNode(1);
    return pre->next;
}