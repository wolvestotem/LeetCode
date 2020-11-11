#pragma once
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(nullptr){}
};