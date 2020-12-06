## 题目

654. Maximum Binary Tree
Medium

Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

    The root is the maximum number in the array.
    The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
    The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.

Construct the maximum tree by the given array and output the root node of this tree. 

## 题解

结构非常鲜明的递归题目，节点中找出范围内最大值，并构造节点，然后递归地解决左右子节点的问题

```C++
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
    TreeNode* hh(vector<int>& nums, int start, int end){
        if(start>end) return nullptr;
        
        int m = INT_MIN;
        int index;
        for(int i=start;i<=end;i++){
            m = max(m,nums[i]);
            if(m==nums[i])
                index=i;
        }
        TreeNode* root = new TreeNode(m);
        root->left = hh(nums,start,index-1);
        root->right = hh(nums,index+1,end);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        return hh(nums,0,nums.size()-1);
    }
};
```