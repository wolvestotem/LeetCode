
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
    bool IterisSymmetric(TreeNode* root);//Iterative
    bool isSymmetric(TreeNode* root);//recursive
    bool ismirror(TreeNode* t1, TreeNode* t2);
};

bool Solution::ismirror(TreeNode* t1, TreeNode* t2){
    if(!t1 && !t2) return(true);
    if(!t1 || !t2) return(false);
    return (t1->val==t2->val)&&(ismirror(t1->left,t2->right))&&(ismirror(t2->left,t1->right));
}

bool Solution::isSymmetric(TreeNode* root){
    return ismirror(root,root);
}