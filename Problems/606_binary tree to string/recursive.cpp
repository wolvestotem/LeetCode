
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
    string tree2str(TreeNode* t);
};

string Solution::tree2str(TreeNode* t){
    if(!t) return("");
    string left = tree2str(t->left);
    string right = tree2str(t->right);
    string valstr = to_string(t->val);
    if(left=="" and right=="")
        return valstr;
    else if(right=="")
        return valstr+'('+left+')';
    else if(left=="")
        return valstr+"()"+'('+right+')';
    else
        return valstr+'('+left+')'+'('+right+')';
}