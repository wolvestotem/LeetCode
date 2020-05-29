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
    vector<int> rightSideView(TreeNode* root){
        vector<int> result;
        if(!root) return result;
        TreeNode *tem;
        int depth;
        stack<pair<TreeNode*,int>> s;
        s.push(make_pair(root,0));
        unordered_set<int> m;

        while(!s.empty()){
            tem = s.top().first;
            depth = s.top().second;
            s.pop();
            if(m.find(depth)==m.end()){
                m.insert(depth);
                result.push_back(tem->val);
            }
            if(tem->left)  s.push(make_pair(tem->left,depth+1));
            if(tem->right) s.push(make_pair(tem->right,depth+1));
        }
        return result;
    }
};