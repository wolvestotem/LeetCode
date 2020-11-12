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
    int tilt=0;
    int tranverse(TreeNode* root){
        if(!root) return(0);
        int left = tranverse(root->left);
        int right = tranverse(root->right);
        tilt+=abs(right-left);//左右和之差---------recurse 不一定返回直接结果，可以在recurse中得到全局结果
        return(left+right+root->val);
    }
    int findTilt(TreeNode* root) {
        if(!root) return(0);
        tranverse(root);
        return(tilt);
    }
};