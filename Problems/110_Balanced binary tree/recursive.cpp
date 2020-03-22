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
    bool isBalanced(TreeNode* root);
    int getheight(TreeNode* root);
};

int Solution::getheight(TreeNode* root){
    if(!root) return(0);
    return max(getheight(root->left),getheight(root->right))+1;
}

bool Solution::isBalanced(TreeNode* root){
    if(!root) return(true);
    int left = getheight(root->left);
    int right = getheight(root->right);
    if ((abs(left-right)<=1) && isBalanced(root->left) && isBalanced(root->right))
        return(true);
    return(false);
}