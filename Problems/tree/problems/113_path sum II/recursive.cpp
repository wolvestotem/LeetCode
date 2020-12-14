/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include"../leetcode.h"
class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> iterpathSum(TreeNode* root, int sum);
    vector<vector<int>> pathSum(TreeNode* root, int sum);
    void repathsum(TreeNode* root, int curr_sum, int sum, vector<int>& path);
};



void Solution::repathsum(TreeNode* root, int curr_sum, int sum, vector<int>& path){
    if(!root) return;
    curr_sum += root->val;
    path.push_back(root->val);
    if(curr_sum==sum && !root->left && !root->right){
        result.push_back(path);
        path.pop_back();
        return;
    }
    if(root->left) repathsum(root->left,curr_sum,sum,path);
    if(root->right) repathsum(root->right,curr_sum,sum,path);
    path.pop_back();
    
    
}

vector<vector<int>> Solution::pathSum(TreeNode* root, int sum){
    vector<int> path;
    int curr_sum=0;
    if(!root) return{};
    repathsum(root,curr_sum,sum,path);//通过构造需要的输入函数递归
    return result;
}