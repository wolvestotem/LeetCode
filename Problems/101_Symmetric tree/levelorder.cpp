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
    bool IterisSymmetric(TreeNode* root);//Iterative
    bool isSymmetric(TreeNode* root);//recursive
    bool ismirror(TreeNode* t1, TreeNode* t2);
};

bool Solution::IterisSymmetric(TreeNode* root){
    queue<TreeNode*> ql, qr;
    if(!root) return(true);
    ql.push(root); qr.push(root);
    TreeNode* r;TreeNode *l;
    while(!ql.empty()&&!qr.empty()){
        r = qr.front(); l = ql.front();
        if (r->val!=l->val) return(false);
        qr.pop(); ql.pop();
        if((!r->right && l->left)||(r->right && !l->left)||(!l->right && r->left)||(l->right && !r->left)) return(false);
        if(r->right) qr.push(r->right);
        if(r->left) qr.push(r->left);
        if(l->left) ql.push(l->left);
        if(l->right) ql.push(l->right);
    }
    if(!ql.empty()||!qr.empty()) return(false);
    return(true);
}
