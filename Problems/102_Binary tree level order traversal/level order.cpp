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
    vector<vector<int>> result;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tem;
        while(!q.empty()){
            int n = q.size();
            vector<int> inter;
            while(n--){
                tem = q.front();
                q.pop();
                inter.push_back(tem->val);
                if(tem->left) q.push(tem->left);
                if(tem->right) q.push(tem->right);
            }
            result.push_back(inter);
        }
        return result;
    }
};