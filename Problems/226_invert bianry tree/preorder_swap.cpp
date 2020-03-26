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

TreeNode* Solution::invertTree(TreeNode* root){
    if(!root) return(nullptr);
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* inter;
    TreeNode* curr;
    while(!q.empty()){
        inter = q.front();
        q.pop();
        curr = inter->left;
        inter->left = inter->right;
        inter->right = curr;
        if(inter->left) q.push(inter->left);
        if(inter->right) q.push(inter->right);
    }
    return(root);
}