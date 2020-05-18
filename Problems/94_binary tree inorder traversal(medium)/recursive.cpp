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
    vector<int> result;//recursive 中常用全局记录结果
public:
    
    vector<int> inorderTraversal(TreeNode* root);
};
vector<int> Solution::inorderTraversal(TreeNode* root){
    if(root){
        inorderTraversal(root->left);
        result.push_back(root->val);
        inorderTraversal(root->right);
    }
    return result;
}