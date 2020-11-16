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
    TreeNode* res;
    bool flag=true;
public:
    int recur(TreeNode* p, TreeNode* q, TreeNode* root){
        if(root==nullptr)
            return 0;
        int sum=0;
        
        
        if(root->left) sum+=recur(p,q,root->left);
        if(root->right) sum+=recur(p,q,root->right);
        
        if(root==p)
            sum+=1;
        if(root==q)
            sum+=1;
        if(sum==2 && flag){
            res= root;
            flag=false;
        }
        return sum;
        
        // if(root->left) recur(p,q,root->left);
        // if(root->right) recur(p,q,root->right);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int s = recur(p,q,root);
        return res;
    }
};