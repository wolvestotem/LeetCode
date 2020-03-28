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
    vector<double> averageOfLevels(TreeNode* root) {//!!!!!!double类型
        vector<double> result;//对应的doubl类型
        if(!root) return(result);
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* inter;
        int curr;
        double aver;
        while(!q.empty()){
            curr = q.size();
            double sum=0;
            for(int i=0; i<curr; i++){
                inter=q.front();
                q.pop();
                sum+=inter->val;
                if(inter->left) q.push(inter->left);
                if(inter->right) q.push(inter->right);
            }
            aver = sum/curr;//注意强制类型转换  int/int=int
            result.push_back(aver);
        }
        return(result);
    }
};