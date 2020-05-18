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
    vector<int> result;
    vector<int> inorderTraversal(TreeNode* root);
    void goalong(TreeNode* root, stack<TreeNode*>& s);
};

void Solution::goalong(TreeNode* root, stack<TreeNode*>& s){//node本身全部入栈
    while(root){
        s.push(root);
        root = root->left;
    }
}

vector<int> Solution::inorderTraversal(TreeNode* root){
    vector<int> res;
    if(!root) return res;
    TreeNode* x(root);
    stack<TreeNode*> s;
    while(true){
        goalong(x,s);
        if(s.empty()) break;
        x = s.top();//visit node本身
        s.pop();
        res.push_back(x->val);
        x = x->right;//node->right
    }
    return res;
}

