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
    TreeNode* sortedArrayToBST(vector<int>& nums);
    TreeNode* BST(vector<int>& nums, int lo, int hi);
};

TreeNode* Solution::BST(vector<int>& nums, int lo, int hi){
    if(lo>=hi) return(nullptr);
    int mi = (lo+hi)>>1;
    TreeNode* root = new TreeNode(nums[mi]);
    root->left = BST(nums, lo, mi);
    root->right = BST(nums, mi+1, hi);
    return root;
}

TreeNode* Solution::sortedArrayToBST(vector<int>& nums){
    if(nums.empty()) return(nullptr);
    int lo = 0;
    int hi = nums.size();
    return BST(nums, lo, hi);
}