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
    
};


bool Solution::prefstisSameTree(TreeNode* p, TreeNode* q){
    if(!p && !q) return(true);
    if((p&&!q) || (!p&&q)) return(false);
    stack<TreeNode*> Sp;
    stack<TreeNode*> Sq;
    Sp.push(p);
    Sq.push(q);
    int pval,qval;
    while(!Sp.empty() && !Sq.empty()){
        p=Sp.top();Sp.pop();
        q=Sq.top();Sq.pop();
        if(p->val!=q->val)return false;
        if((p->left&&!(q->left)) || (!(p->left)&&q->left)) return(false);//平凡情况，nullptr判断结构一致性
        if((p->right&&!(q->right)) || (!(p->right)&&q->right)) return(false);
        if(p->right) Sp.push(p->right);
        if(q->right) Sq.push(q->right);
        if(p->left) Sp.push(p->left);
        if(q->left) Sq.push(q->left);
    }
    if(!Sp.empty() || !Sq.empty()) return(false);
    return true;
}
