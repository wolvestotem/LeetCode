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
    int Pathcount = 0;
    int pathSum(TreeNode* root, int sum);
    void sumI(TreeNode* root, int sum);
};

int Solution::pathSum(TreeNode* root, int sum){
    if(root){
        sumI(root,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
    }
    return(Pathcount);
}

void Solution::sumI(TreeNode* root, int sum){
    if(root){
        if(root->val==sum)
            Pathcount++;
        sumI(root->left, sum-root->val);
        sumI(root->right, sum-root->val);
    }
}