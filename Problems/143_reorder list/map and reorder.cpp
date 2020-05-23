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
    void reorderList(ListNode* head) {
        if(!head) return;
        if(!head->next) return;
        int rank(1);
        ListNode* curr(head);
        unordered_map<int,ListNode*> m;
        while(curr){
            m[rank] = curr;
            rank++;
            curr = curr->next;
        }
        int left(1),right(rank-1);
        ListNode *fir,*sec;
        bool lside = true;
        while(left<right){
            if(lside){
                fir = m[left];
                sec = m[right];
                fir->next = sec;
                lside = false;
                left++;
            }
            else{
                fir = m[right];
                sec = m[left];
                fir->next = sec;
                lside = true;
                right--;
            }
        }
        sec->next=nullptr;
    }
};
