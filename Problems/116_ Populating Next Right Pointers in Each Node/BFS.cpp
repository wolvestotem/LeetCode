#include"../leetcode.h"


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        Node *tem,*pre;
        int n;
        while(!q.empty()){
            n = q.size();
            for(int i=1;i<=n;i++){
                tem = q.front();q.pop();
                if(i==1){
                    tem->next = nullptr;
                    pre = tem;
                }
                else{
                    tem->next = pre;
                    pre = tem;
                }
                if(tem->right) q.push(tem->right);
                if(tem->left) q.push(tem->left);
            }
        }
        return root;
    }
};