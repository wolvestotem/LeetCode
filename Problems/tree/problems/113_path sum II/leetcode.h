#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
#include<iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};