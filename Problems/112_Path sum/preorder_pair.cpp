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
    bool iterhasPathSum(TreeNode* root, int sum);
    bool hasPathSum(TreeNode* root, int sum);
};

bool Solution::iterhasPathSum(TreeNode* root, int sum){
    if(!root) return(false);
    stack<pair<TreeNode*,int>> s;
    s.push({root, root->val});
    TreeNode* inter;
    while(!s.empty()){
        int total = s.top().second;
        inter = s.top().first;
        s.pop();
        if(inter->left) s.push({inter->left, total+inter->left->val});
        if(inter->right) s.push({inter->right, total+inter->right->val});
        if(total==sum && !inter->right && !inter->left)
            return(true);
    }
    return (false);
}
