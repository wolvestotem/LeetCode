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
#include<vector>
class Solution {
    struct Node{//DFS中，pair不足以记录信息时，用struct记录信息
        TreeNode* curr;
        int sum;
        vector<int> vec;
    };
    vector<vector<int>> result;
public:
    vector<vector<int>> iterpathSum(TreeNode* root, int sum);
    vector<vector<int>> pathSum(TreeNode* root, int sum);
    void repathsum(TreeNode* root, int curr_sum, int sum, vector<int> path);
};


vector<vector<int>> Solution::iterpathSum(TreeNode* root, int sum){
    vector<int> path;
    if(!root) return {};
    stack<Node> s;
    s.push({root,0,{}});
    while(!s.empty()){
        Node inter = s.top();
        s.pop();
        
        TreeNode* curr = inter.curr;
        int curr_sum = inter.sum+curr->val;
        path = inter.vec;
        
        path.push_back(curr->val);
        
        if(curr_sum==sum && !curr->left && !curr->right)
            result.push_back(path);
        if(curr->left) s.push({curr->left,curr_sum,path});
        if(curr->right) s.push({curr->right,curr_sum,path});
    }
    return(result);
}
