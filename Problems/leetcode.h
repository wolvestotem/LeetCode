#pragma once
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
#include<iostream>
#include<unordered_map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};