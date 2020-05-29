#include"../leetcode.h"

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
    bool valid(TreeNode* root, long lo, long hi){
        if(!root) return true;
        if(root->val<=lo || root->val>=hi) return false;
        return valid(root->left, lo, root->val) && valid(root->right, root->val, hi);
    }

    bool isValidBST(TreeNode* root) {
        return valid(root, (long)INT_MIN-1, (long)INT_MAX+1);
    }
};