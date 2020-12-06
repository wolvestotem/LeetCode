对于二叉树问题应该先想到使用递归方法解决问题
本题应该采用后序遍历
```C++
void flatten(TreeNode* root){
    if(!root) return;
    flatten(root->left);
    flatten(root->right);
    TreeNode* tem = root->right;
    root->right = root->left;
    root->left = nullptr;
    while(root->right){
        root = root->right;
    }
    root->right = tem;
}
```