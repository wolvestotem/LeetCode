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
    long int pre = -2147483650;//smaller than INT_MIN
    bool result = true;
public:
    void inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            if(pre>=root->val)
                result = false;
            else
                pre = root->val;
            inorder(root->right);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return result;
    }
};