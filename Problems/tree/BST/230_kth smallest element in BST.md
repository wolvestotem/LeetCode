230. Kth Smallest Element in a BST
Medium

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

## 题解

中序遍历是有序的，找到中序遍历中第k个节点

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
    int res=0;
    int rank=0;
public:
    void traverse(TreeNode* root, int k){
        if(!root) return;
        
        traverse(root->left,k);
        rank++;
        if(rank==k){
            res = root->val;
            return;
        }
        traverse(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        traverse(root,k);
        return res;
    }
};
```

## 延伸

要知道 BST 性质是非常牛逼的，像红黑树这种改良的自平衡 BST，增删查改都是O(logN)的复杂度，让你算一个第k小元素，时间复杂度竟然要O(N)，有点低效了。

所以说，计算第k小元素，最好的算法肯定也是对数级别的复杂度，不过这个依赖于 BST 节点记录的信息有多少。

我们想一下 BST 的操作为什么这么高效？就拿搜索某一个元素来说，BST 能够在对数时间找到该元素的根本原因还是在 BST 的定义里，左子树小右子树大嘛，所以每个节点都可以通过对比自身的值判断去左子树还是右子树搜索目标值，从而避免了全树遍历，达到对数级复杂度。

那么回到这个问题，想找到第k小的元素，或者说找到排名为k的元素，如果想达到对数级复杂度，关键也在于每个节点得知道他自己排第几。

比如说你让我查找排名为k的元素，当前节点知道自己排名第m，那么我可以比较m和k的大小：

1、如果m == k，显然就是找到了第k个元素，返回当前节点就行了。

2、如果k < m，那说明排名第k的元素在左子树，所以可以去左子树搜索第k个元素。

3、如果k > m，那说明排名第k的元素在右子树，所以可以去右子树搜索第k - m - 1个元素。

这样就可以将时间复杂度降到O(logN)了。

那么，如何让每一个节点知道自己的排名呢？

这就是我们之前说的，需要在二叉树节点中维护额外信息。每个节点需要记录，以自己为根的这棵二叉树有多少个节点。

也就是说，我们TreeNode中的字段应该如下：
```C++
class TreeNode {
    int val;
    // 以该节点为根的树的节点总数
    int size;
    TreeNode left;
    TreeNode right;
}
```
有了size字段，外加 BST 节点左小右大的性质，对于每个节点node就可以通过node.left推导出node的排名，从而做到我们刚才说到的对数级算法。

当然，size字段需要在增删元素的时候需要被正确维护，力扣提供的TreeNode是没有size这个字段的，所以我们这道题就只能利用 BST 中序遍历的特性实现了，但是我们上面说到的优化思路是 BST 的常见操作，还是有必要理解的。


于是，我们对原始框架进行改造，抽象出一套针对 BST 的遍历框架：
```C++
void BST(TreeNode root, int target) {
    if (root.val == target)
        // 找到目标，做点什么
    if (root.val < target) 
        BST(root.right, target);
    if (root.val > target)
        BST(root.left, target);
}
```
这个代码框架其实和二叉树的遍历框架差不多，无非就是利用了 BST 左小右大的特性而已。

