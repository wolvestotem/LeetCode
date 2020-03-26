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
    vector<vector<int>> levelOrderBottom(TreeNode* root);
};

vector<vector<int>> Solution::levelOrderBottom(TreeNode* root){
    vector<vector<int>> result;
    if(!root) return(result);
    queue<TreeNode*> q;
    q.push(root);
    int curr;
    TreeNode* inter;
    while(!q.empty()){
        curr = q.size();//每层元素个数
        vector<int> level;
        for (int i = 0; i<curr; i++){
            inter = q.front();//注意！！！queue中front(),back()
            q.pop();
            level.push_back(inter->val);
            if(inter->left) q.push(inter->left);
            if(inter->right) q.push(inter->right);
        }
        result.push_back(level);
    }
    reverse(result.begin(),result.end());
    return(result);//注意return返回值
}