#include"../leetcode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
       if(!head) return nullptr;
       if(!head->next) return new TreeNode(head->val);

       ListNode* fa(head),*lo(head);
       if(fa && fa->next){
           fa = fa->next->next;
       }
       while(fa && fa->next){
           fa = fa->next->next;
           lo = lo->next;
       } 
       ListNode* mid = lo->next;
       ListNode* right = mid->next;
       lo->next = nullptr;
       mid->next = nullptr;
       TreeNode* root = new TreeNode(mid->val);
       root->left = sortedListToBST(head);
       root->right = sortedListToBST(right);
       return root;
    }
};