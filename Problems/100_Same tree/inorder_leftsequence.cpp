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
    //different methods
    bool fstisSameTree(TreeNode* p, TreeNode* q);//recursive
    bool prefstisSameTree(TreeNode* p, TreeNode* q);//preorder 栈混洗
    bool presndisSameTree(TreeNode* p, TreeNode* q);//preorder 左序列
    bool isSameTree(TreeNode* p, TreeNode* q); //inorder 左序列
    
    //support function
    bool compareLB(TreeNode* p, TreeNode* q, stack<TreeNode*>& Sp, stack<TreeNode*>& Sq);//support preorder func
    bool goalongLB(TreeNode* p, TreeNode* q, stack<TreeNode*>& Sp, stack<TreeNode*>& Sq);//support inorer func
};

bool Solution::goalongLB(TreeNode* p, TreeNode* q, stack<TreeNode*>& Sp, stack<TreeNode*>& Sq){
    if(!p&&!q) return(true);
    if((p&&!q) || (!p&&q)) return(false);
    while(p && q){
        Sp.push(p);//push itself!! nullptr is not allowed in the stack
        Sq.push(q);//push itself!! nullptr is not allowed in the stack
        p = p->left;
        q = q->left;
    }
    if(p || q) return(false);
    return true;
}

bool Solution::isSameTree(TreeNode* p, TreeNode* q){//inorder
    stack<TreeNode*> Sp; stack<TreeNode*> Sq;
    bool result = true;
    while(true){
        result = result&&goalongLB(p,q,Sp,Sq);
        if(!result) return(false);
        if(Sp.empty() || Sq.empty()) break;
        p = Sp.top();Sp.pop();
        q = Sq.top();Sq.pop();
        if(p->val!=q->val) return(false);
        p = p->right;
        q = q->right;
    }
    if(!Sp.empty() || !Sq.empty())return(false);
    return(result);
}
