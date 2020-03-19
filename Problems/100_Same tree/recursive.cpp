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
    bool fstisSameTree(TreeNode* p, TreeNode* q);//recursive
};

bool Solution::fstisSameTree(TreeNode* p, TreeNode* q){
    if(!p && !q) return(true);
    if((p&&!q) || (!p&&q)) return(false);
    bool result = true;
    if(p->val!=q->val) return(false);
    result = result&&isSameTree(p->left,q->left);
    result = result&&isSameTree(p->right,q->right);
    return(result);
}
