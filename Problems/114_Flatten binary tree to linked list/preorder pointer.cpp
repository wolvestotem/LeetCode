#include"../leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*> s;
        TreeNode* head(root);
        TreeNode* tem;
        s.push(root);
        bool start=false;
        while(!s.empty()){
            tem = s.top();
            s.pop();
            if(start){//从第二次开始
                head->left = nullptr;
                head->right = tem;
                head = head->right;
            }
            if(tem->right) s.push(tem->right);
            if(tem->left) s.push(tem->left);
            start = true;
        }
    }
};
