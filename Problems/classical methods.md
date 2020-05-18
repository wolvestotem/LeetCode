# 经典方法总结

## Tree Transverse

### pre-order recursive

```C++
vector<int> result;
vector<int> preorder(TreeNode* root){
    while(root){
        result.push_back(root);
        preorder(root->left);
        preorder(root->right);
    }
    return result;
}
```

### preorder iteration

```C++
vector<int> preorder(TreeNode* root){
    vector<int> result;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode* tem;
    while(!s.empty()){
        tem = s.top();
        s.pop();
        result.push_back(s->val);
        if(tem->right) s.push(tem->right);
        if(tem->left) s.push(tem->left);
    }
    return result;
}
```

### inorder recursive

```C++
vector<int> result;
vector<int> Solution::inorderTraversal(TreeNode* root){
    if(root){
        inorderTraversal(root->left);
        result.push_back(root->val);
        inorderTraversal(root->right);
    }
    return result;
}
```

### inorder iteration

```C++
void Solution::goalong(TreeNode* root, stack<TreeNode*>& s){//node本身全部入栈
    while(root){
        s.push(root);
        root = root->left;
    }
}

vector<int> Solution::inorderTraversal(TreeNode* root){
    vector<int> res;
    if(!root) return res;
    TreeNode* x(root);
    stack<TreeNode*> s;
    while(true){
        goalong(x,s);
        if(s.empty()) break;
        x = s.top();//visit node本身
        s.pop();
        res.push_back(x->val);
        x = x->right;//node->right
    }
    return res;
}
```

### BFS层析遍历法
```C++
vector<int> bfs(TreeNode* root){
    vector<int> result;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* tem;
    while(!q.empty()){
        tem = q.front();
        q.pop();
        result.push_back(tem->val);
        if(tem->left) q.push(tem->left);
        if(tem->right) q.push(tem->right);
    }
    return result;
}
```