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

### Serialize tree（唯一确定一颗子树）

```C++
string serilize(TreeNode* root){
        if(!root){
            return "#";
        }
        string l = serilize(root->left);
        string r = serilize(root->right);
        string v = to_string(root->val);
        string res = l+","+r+","+v;

        return res;
    }
```

## Reverse Linked list

### Iteration

```C++
ListNode* reverse(ListNode* head) {
    if (!head) return nullptr;
    ListNode* curr = head;
    ListNode* pre = nullptr;
    ListNode* fu=head;
    while (fu) {
        fu = curr->next;
        curr->next = pre;
        pre = curr;
        curr = fu;
    }
    return(pre);
}
```

### Recursion

```C++
ListNode* reverse(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* res = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;

    return res;
}
```

## Linked list取中点
```C++
void mid(ListNode* head){
    if(!head || !head->next)
        return head;
    ListNode *sl(head),*fa(head->next);

    while(fa && fa->next){
        sl = sl->next;
        fa = fa->next->next;
    }
}
```

## Traverse Graph

### topological traverse

```C++
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        int V=numCourses;
        vector<vector<int>> graph(V,vector<int>{});//出度
        vector<int> degree(V,0);//入度 另行记录！！
        for(auto v:prerequisites){
            graph[v[1]].push_back(v[0]);
            degree[v[0]]++;
        }
        for(int i=0;i<V;i++){
            if(degree[i]==0)
                q.push(i);
        }

        vector<int> res;
        // int count=0;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            res.push_back(t);
            // count++;
            for(auto node:graph[t]){
                if(--degree[node]==0)
                    q.push(node);
            }
        }
        if(res.size()==V)
            return res;
        else
            return vector<int>{};
    }
```

