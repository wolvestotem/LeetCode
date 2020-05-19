#include"../leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos=0;
        return mytree(preorder, pos, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* mytree(vector<int>& preorder, int& pos, vector<int>& inorder, int inL, int inR){
        if(pos>=preorder.size()) return nullptr;
        TreeNode* root = new TreeNode(preorder[pos]);
        int num=0;
        for(num=inL;num<=inR;num++){
            if(preorder[pos]==inorder[num])
                break;
        }
        if(inL<num) root->left = mytree(preorder, ++pos, inorder, inL, num-1);
        if(num<inR) root->right = mytree(preorder, ++pos, inorder, num+1, inR);
        return root;
    }
};