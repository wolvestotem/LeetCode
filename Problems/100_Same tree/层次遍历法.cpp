
// Definition for a binary tree node.
  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    //different methods
    bool fstisSameTree(TreeNode* p, TreeNode* q);//recursive
    bool prefstisSameTree(TreeNode* p, TreeNode* q);//preorder 栈混洗
    bool presndisSameTree(TreeNode* p, TreeNode* q);//preorder 左序列
    bool inisSameTree(TreeNode* p, TreeNode* q); //inorder 左序列
    bool isSameTree(TreeNode* p, TreeNode* q);//层次遍历法-----严格的顺序结构
    
    
    //support function
    bool compareLB(TreeNode* p, TreeNode* q, stack<TreeNode*>& Sp, stack<TreeNode*>& Sq);//support preorder func
    bool goalongLB(TreeNode* p, TreeNode* q, stack<TreeNode*>& Sp, stack<TreeNode*>& Sq);//support inorer func
};


bool Solution::isSameTree(TreeNode* p, TreeNode* q){
    if(!p && !q) return(true);
    if((p&&!q) || (!p&&q)) return(false);
    queue<TreeNode*> Qp,Qq;
    Qp.push(p);
    Qq.push(q);
    while(!Qp.empty() && !Qq.empty()){
        p = Qp.front();q=Qq.front();
        if(p->val!=q->val) return(false);
        Qp.pop();Qq.pop();
        if((p->left&&!(q->left)) || (!(p->left)&&q->left)) return(false);//平凡情况，nullptr判断结构一致性!!!!!!!
        if((p->right&&!(q->right)) || (!(p->right)&&q->right)) return(false);
        if(p->left) Qp.push(p->left);
        if(p->right) Qp.push(p->right);
        if(q->left) Qq.push(q->left);
        if(q->right) Qq.push(q->right);
    }
    if(!Qp.empty() || !Qq.empty()) return(false);
    return(true);
}