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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        TreeNode *tem;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 1; i<=n; i++){
                tem = q.front();
                q.pop();
                if(i==1){
                    result.push_back(tem->val);
                }
                if(tem->right) q.push(tem->right);
                if(tem->left) q.push(tem->left);
            }
        }
        return result;
    }
};