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

bool Solution::compareLB(TreeNode* p, TreeNode* q, stack<TreeNode*>& Sp, stack<TreeNode*>& Sq){
    bool result = true;
    if((p&&!q) || (!p&&q)) return(false);
    if(!p && !q) return(true);
    while(p && q){
        if(p->val!=q->val)return false;
        Sp.push(p->right);
        Sq.push(q->right);
        p = p->left;
        q = q->left;
    }
    if(p || q) return(false);
    return result;
}


bool Solution::presndisSameTree(TreeNode* p, TreeNode* q){//preorder left_sequence
    stack<TreeNode*> Sp; stack<TreeNode*> Sq;
    bool result = true;
    while(true){
        result = result&&compareLB(p,q,Sp,Sq);
        if(!result) return(false);
        if(Sp.empty() || Sq.empty()) break;
        p = Sp.top(); Sp.pop();
        q = Sq.top(); Sq.pop();
    }
    if(!Sp.empty() || !Sq.empty()) return(false);
    return(result);
}

