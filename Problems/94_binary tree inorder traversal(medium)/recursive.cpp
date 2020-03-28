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
    void tran(TreeNode* root);
};
vector<int> Solution::inorderTraversal(TreeNode* root){
    if(!root) return(result);
    tran(root);
    return(result);
}
void Solution::tran(TreeNode* root){//通过全局result得到结果，而不必直接return结果
    if(root){//--------------void递归中常用
        tran(root->left);
        result.push_back(root->val);
        tran(root->right);
    }
}