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
    int maxpath=INT_MIN;//全局变量得到全局最大值
public:
    int diameterOfBinaryTree(TreeNode* root);
    int pathofbt(TreeNode* root);
};

int Solution::pathofbt(TreeNode* root){//根据递归需求找输入输出，，直接结果并不一定是所求
    if(!root) return 0;
    int left = pathofbt(root->left);
    int right = pathofbt(root->right);
    int path = left+right+1;
    maxpath = max(maxpath,path);
    return max(left,right)+1;
}

int Solution::diameterOfBinaryTree(TreeNode* root){
    if(!root) return(0);
    int path = pathofbt(root);
    return(maxpath-1);
}