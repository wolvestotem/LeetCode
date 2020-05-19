Leetcode Problems #1--#400
============

### 2 Add two number(Linked list)
一个充满细节考量的加法器。我自己使用一个时间复杂度和空间复杂度高的方法，迭代地使用加法器，并构造了一个新的Linked List序列记录结果。

细节：

需要一个全局进位计数器变量，**加法器运行截止至 l1,l2,进位都为空时**，之前犯错误l1,l2其一为空就停止，实际还应该考虑进位对飞空list影响。**对空指针数值和递归使用都需要分类讨论**

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    int add=0;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2 && !add)//正确的截止条件---全部计算结束时
            return nullptr;
        int a,b;
        a = (l1)?l1->val:0;//空指针数值讨论
        b = (l2)?l2->val:0;
        int sum = (a+b+add);
        add = sum/10;
        ListNode* head;
        if(l1 && l2)
            head = new ListNode(sum%10,addTwoNumbers(l1->next,l2->next));
        else{
            if(!l1 && !l2)//空指针递归使用讨论
                head = new ListNode(sum%10,addTwoNumbers(nullptr,nullptr));
            else
                head = (l1)?new ListNode(sum%10,addTwoNumbers(l1->next,nullptr)):new ListNode(sum%10,addTwoNumbers(nullptr,l2->next));
        }
        return head;
    }
};
```

### 7 Reverse integer

+ 只能32位integer

关键点在于`INT_MAX`比`INT_MIN`绝对值小1，所以不能对称的判断，而要分正负讨论

另外对负数求余还是负数，可以直接求余入队

+ 可以使用long

使用string可以更加方便的换顺序，最后加以验证

### 11 Container with most water

最值问题，但是并不是用dp解决，思考时候限于dp太多

brute force其实就比较好，`T(n)=O(n2)`，比较简单

Discussion给出two pointers 解法。数组经常用左右指针，linked list经常用快慢指针。


### 19 Remove Nth node from the end

本问题有三点值得注意：

+ 是list的问题，可以想到快慢指针，利用指针步数度量
+ 利用pre指针更好解决list问题，返回pre->next，而不是head，防止head被影响
+ 更好的初始化策略

```C++
// Initialization
ListNode *fir(pre), *sec(pre);
ListNode *fir{pre};
```

### 22 Generate parentheses

本题关键点：backtracking，类似于permutation，或者DFS+剪枝。利用recurse充分讨论每层的所有情况，直至讨论结束。设计DFS剪枝方向时候，应该想好怎么判断，本题中用open,close,显然由于stack。

```C++
class Solution {
    vector<string> result;
public:
    vector<string> generateParenthesis(int n);
    void recur(int m, int open, int close ,string str,int n);
};

void Solution::recur(int m, int open, int close ,string str,int n){
    if(m==0){//结束
        result.push_back(str);
        return;
    }
    else{
        if(open<n){
            recur(m-1,open+1,close,str+"(",n);//函数参数可以直接计算
        }
        if(close<open){
            recur(m-1,open,close+1,str+")",n);
        }
    }
}
vector<string> Solution::generateParenthesis(int n){
    int open=0;
    int close=0;
    string r="";
    recur(2*n,open,close,r,n);
    return result;
}
```

### 34 Find first and last position of element in sorted array

使用`Binary search`分别寻找区间左端点和右端点，找不到则返回-1。详情见[Binary Search](..\Binary search\思路.md)

### 39 Combination Sum

一次写得不错的permutation likely题目，同样是使用DFS+剪枝。本题目中最值得注意的是`Combination`而非`Permutation`，使用`rank`控制DFS只遍历当前和之后的`candidates`，而不去寻找之前的，保证了不重复的组合。


### 46 Permutation

这题是一个正经的permutation，而不是perm的变式。关键点在于使用一个`hash map`计量一个元素是否使用过，不再重复使用

本题中主要出错点在`unordered_map.count`和`unordered_map.find`使用场景不清晰。使用过元素后，即使value归零，依然可以`find`到元素，`count`和`find`是完全相同功能函数。

在类似本题的计量一个元素是否出现场景下，可以初始化map后就是用`value`计数；也可以创建元素后`unoedered_map.erase(key)`复原。使用`value`计数效率更高。

```C++
for(int i:nums)//初始化
    m[i]=0;

if(!m[i])
    m[i]++;//value
    recur(...);
    m[i]--;
```

```C++
if(m.find(i)==m.end())
    m[i]++;
    recur(...);
    m.erase(i);//删除key
```

### 48 Rotate Image

这是一道完全的数学找规律题目，通过`Transpose`+每行`reverse`实现矩阵顺时针旋转，不具有普适意义。

### 49 Group Anagram

一道经典的字符串乱序相等问题，是字符串乱序包含的子问题（B是否所有字母都在A中），一般认为有三种方法:

- sort and compare
- alpha vector
- prime number

**sort and compare**
本题中因为是相等问题，可以使用`hash table`极大简化比较过程，`sort`后的线性比较变成了在`hash`中查找。应该注意`hash table`本题中的灵活用法。


```C++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<vector<string>> result;
        if(strs.empty()) return(result);
        unordered_map<string,vector<string>> m;//hash table 可以用vector作为value

        for(string str:strs){
            string s = str;
            sort(s.begin(),s.end());
            m[s].push_back(str);//用key-value直接查找
        }
        for(auto tem:m){
            result.push_back(tem.second);//m.second m.first使用
        }
        return result;
    }
};
```

**prime number**
一种很好的方法，但是需要注意`product`可能是一个很大的数，使用`unsigned long long`

**alpha vector**
常见方法，使用26`vector`标记以个乱序字符串。

### 55 Jump Game

- Dynamic programming

DP经典解法，可以OPT[n]=nums[n]是否从零可达，更简单的从后向前OPT[n]=是否可以从n到达`final`

- Greedy

经典`加油站覆盖`问题，Greedy solution: 每步的最大可达区域，不能低于当前位置

```C++
class Solution {
public:
    //Greedy solution: 每步的最大可达区域，不能低于当前位置
    bool canJump(vector<int>& nums){
        if(nums.empty()) return false;
        int maxjump = 0;
        for(int i=0;i<nums.size();i++){
            if(maxjump<i)
                return false;
            maxjump = max(maxjump,nums[i]+i);
        }
        return true;
    }
};
```

### 56 Merge Intervals

题目思路就是当intervals overlap时，找出最小`start`和最大`end`。先`sort start`，注意**二维矩阵中sort的默认排序是对第一列排序**，默认`sort`比`custom sort`高效。其中也有`加油站覆盖`思想，将`start`排序后，找出能够覆盖的最大值，并合并成一个interval。

### 64 Minimum Path Sum

经典DP问题，注意的是`base case`的初始化问题。`table`的第一行第一列要单独初始化

```C++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> table(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1)//初始化第1行，第1列
                    table[i][j] = table[i][j-1]+grid[i-1][j-1];
                else if(j==1)
                    table[i][j] = table[i-1][j]+grid[i-1][j-1];
                else
                    table[i][j] = min(table[i-1][j],table[i][j-1])+grid[i-1][j-1];//递推式
            }
        }
        return table[m][n];
    }
};
```

### 70 Climbing Stairs

简单的dp规划问题，需要看出爬到第n阶的本质是：通过n-1爬1格，或者n-2爬2格。

### 75 Sort colors

最自然的想法是排序算法`T(n)=O(nlogn)`，但是因为只有三个数，可以cout个数然后初始化得到结果`T(n)=O(n)`，但是空间复杂度`O(n)`。
本题最佳解法是`transverse and swap`，实现排序

```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int index = 0;
        while(index<=right){
            switch(nums[index]){
                case(0):
                    swap(nums[left++],nums[index++]);
                    break;
                case(1):
                    index++;
                    break;
                case(2):
                    swap(nums[index],nums[right--]);//index
                    break;
            }
        }
    }
};
```

### 78 Subsets

可以使用经典`DFS+剪枝`，使用`permutation like`方法组合所有subsets，需要注意的是，使用`reference`必须注意每次调用`recur`函数都要还原所指代的`vector..`

Subset经典思想是通过**二进制数**代表所有位数取与不取，可以让1右移`n-1`位按位与，得到一个subset

```C++
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int s=pow(2,n)-1;

        vector<vector<int>> result;
        vector<int>v;
        for(int i=0;i<=s;i++){
            for(int j=0;j<n;j++){
                if(i & (1<<j))//1向右移逐位扫描，扫到得1
                    v.push_back(nums[j]);
            }
            result.push_back(v);
            v.clear();
        }
        return result;
    }
};
```

### 79 Word Search

**重要的二维DFS剪枝题目，可以通过本题一窥图算法中的DFS用法**。

- 题目DFS使用方法本质没变，只是使用`x,y`二维坐标指示搜索位置。
- **返回值是bool类型，使本题更容易标识`base case`和越界条件**。
- **利用`reference`recursive前后不变标识走过的路，防止重复走路**

```C++
class Solution {
    string s;
public:
    bool dfs(vector<vector<char>>& board, int index, int x, int y){//返回bool类型
        bool result;
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size())//临界条件
            return false;
        if(s[index]!=board[x][y])
            return false;
        if(index>=s.size()-1) 
            return true;
        char temp = board[x][y];
        board[x][y] = '$';//---------------标识走过的路
        result = dfs(board,index+1,x-1,y) || dfs(board,index+1,x+1,y) || dfs(board,index+1,x,y-1) || dfs(board,index+1,x,y+1);
        board[x][y]=temp;//----------------还原路程
        return result;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        s = word;
        int m = board.size();
        int n = board[0].size();
        bool result = false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==s[0])
                    result = dfs(board,0,i,j);
                if(result)
                    return true;
            }
        }
        return false;
    }
};
```

### 91 Decode ways

经典dp问题，需要讨论`s[i]`是否为零。

`s[i]`为零，只能`table[i-2]`后者return 0; `s[i]`不为零，讨论后两位是否能decode，分情况说明。

```C++
class Solution {
public:
    int numDecodings(string s);
};

int Solution::numDecodings(string s){
    vector<int> table(s.size()+1,1);
    //base case
    if(s[0]=='0')
        return 0;
    else
        table[1]=1;

    for(int i=2;i<=s.size();i++){
        if(s[i-1]!='0'){
            if(stoi(s.substr(i-2,2))<=26 && stoi(s.substr(i-2,2))>10)
                table[i] = table[i-1]+table[i-2];
            else
                table[i] = table[i-1];
        }
        else{
            if(stoi(s.substr(i-2,2))==10 || stoi(s.substr(i-2,2))==20)
                table[i] = table[i-2];
            else
                return 0;
        }
    }
    return table[s.size()];
}
```

### 94 Binary tree Traversal

经典遍历问题，使用`recursive`和`iteration`分别实现.

### 98 Validate binary search tree

当使用`inorder`遍历搜索二叉树时，应该单调增的，所以遍历，并判断单调性。

### 101 Symmetric Tree

- Iteration方法
两个`queue`分别在每层进行从左向右和从右向左的层次遍历，比较并判断它们是否实时相等。

- recursive方法
两个对应位置`TreeNode`指针，应该判断`->val`相等，`l->left`和`r->right`对称，`l->right`和`r->left`对称

### 102 Binary Tree Level Order Traversal

在层次遍历法中，按照每层进行处理是一种重要的技巧。每次的`q.size()`就是一层中的所有`Node`个数,标准范式如下：

```C++
void level order traversal(){
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* tem;
    while(!q.empty()){
        int n = q.size();
        vector<int> inter;
        while(n--){
            tem = q.front();
            q.pop();
            visit(tem);
            if(tem->left) q.push(tem->left);
            if(tem->right) q.push(tem->right);
        }
    }
}
```

### 104 Max depth of Binary Tree

经典recursive方法，根节点max depth等于左右子节点max depth+1.

### 105 Construct Binary tree from preorder and inorder traversal

本题不具有拓展性，采用recursive分治法结题。依次使用前序元素分割中序数组，分割后递归处理。一开始`pos=0`，以`preorder[pos]`为根，对应`inorder`中全部元素，preorder[pos]在inorder中对应位置p，将inorder分割成`[0,p-1],[p+1,end()]`两部分，对应左子树和右子树。

```C++
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
```

### 114 Flatten Binary tree to Linked list

- `preorder traversal`
本题是按照preorder顺序排列linked list，所以第一感觉是通过`preorder traversal`重新连接TreeNode，实现排列。观察发现将左右孩子入栈后正好可以保护好不被覆盖，所以通过stack存储原节点，通过head重写新Linked list.

- `preorder pointer`
需要观察和对分治思想的领会。对于每个root，将左子树变成右子树，再将右子树连在左子树最右node上，递归实现。

### 121 Best time to buy and sell stock

- 快慢指针
只允许一次买卖操作，并且卖一定快于买，所以使用快慢指针。快慢指针的核心在于，慢指针前移的判断条件和方式。

```C++
int Solution::maxProfit(vector<int>& prices){
    if(prices.size()<2)return(0);
    int profit=0;
    int min = prices[0];
    int size = prices.size();
    for(int i = 1; i<size; i++){
        profit = (prices[i]-min>profit)?(prices[i]-min):profit;
        min = (prices[i]>min)?min:prices[i];
    }
    return(profit);
}
```

- Stock类DP方法

![DP 思路](https://github.com/wolvestotem/LeetCode/blob/master/Problems/Dynamic%20programming/general%E6%80%9D%E8%B7%AF.md)