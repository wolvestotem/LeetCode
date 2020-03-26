class Solution {
public:
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root);
    pair<int,bool> def(TreeNode* root);
};

int Solution::sumOfLeftLeaves(TreeNode* root){
    if(!root) return(0);
    def(root);
    return(sum);
}

pair<int,bool> Solution::def(TreeNode* root){
    pair<int,bool> result;
    bool leave = false;
    if(!root) return(result);
    if(!root->left && !root->right)
        leave = true;
    def(root->right);
    result = def(root->left);
    if(result.second)
        sum=sum+result.first;
    result.first=root->val;
    result.second=leave;
    return(result);
}