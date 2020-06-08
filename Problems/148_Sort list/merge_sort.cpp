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
public:
    ListNode* merge(ListNode* left, ListNode* right){
        if(!right) return left;
        ListNode *pre = new ListNode(0);
        ListNode *curr(pre);
        while(left && right){
            curr->next = (left->val > right->val)?(right):(left);
            curr = curr->next;
            (left->val > right->val)?(right = right->next):(left = left->next);
        }
        if(left || right){
            curr->next = (left)?left:right;
        }
        return pre->next;
    }
    
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;//sort[lo,hi],base case是lo==hi return;
        ListNode *left(head);
        // ListNode *pre = new ListNode(-1);
        // pre->next = head;
        // ListNode *fa(pre),*sl(pre);
        if(!head || !head->next) return head;
        ListNode *fa(head->next), *sl(head);
        
        while(fa && fa->next){
            sl = sl->next;
            fa = fa->next->next;
        }
        ListNode *right(sl->next);
        sl->next = nullptr; 

        // ListNode *oor(right),*ol(left);
        // cout<<"right list is  ";
        // while(oor){
        //     cout<<oor->val<<'\t';
        //     oor = oor->next;
        // }
        // cout<<endl;
        // cout<<"left list is  ";
        // while(ol){
        //     cout<<ol->val<<'\t';
        //     ol=ol->next;
        // }
        cout<<endl;

        ListNode *result,*sortleft,*sortright;
        sortleft = sortList(left);
        sortright = sortList(right);
        
        result = merge(sortleft,sortright);
        return result;
    }

};