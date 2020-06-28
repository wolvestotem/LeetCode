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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tem;
        int size;
        bool left = true;
        stack<TreeNode*> s;
        
        while(!q.empty()){
            size = q.size();
            vector<int> t;
            for(int i=0;i<size;i++){
                tem = q.front();
                q.pop();
                t.push_back(tem->val);
                s.push(tem);
            }
            result.push_back(t);
            while(!s.empty()){
                if(left){
                    tem = s.top();
                    s.pop();
                    if(tem->right) q.push(tem->right);
                    if(tem->left) q.push(tem->left);
                }
                else{
                    tem = s.top();
                    s.pop();
                    if(tem->left) q.push(tem->left);
                    if(tem->right) q.push(tem->right);
                }
            }
            left = !left;
        }
        return result;
    }
};