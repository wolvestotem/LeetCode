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
    TreeNode* invertTree(TreeNode* root);
    TreeNode* recinvertTree(TreeNode* root);
};

TreeNode* Solution::recinvertTree(TreeNode* root){
    if (!root) return(root);
    TreeNode* inter;
    inter = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(inter);
    return(root);
}
