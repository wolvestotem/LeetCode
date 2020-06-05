#include"../leetcode.h"


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*, Node*> m;//善用map  pointer to pointer
        Node *pre = new Node(0);
        Node *curr(pre);
        Node *prehead(head);
        
        while(head){
            Node *tem = new Node(head->val);
            curr->next = tem;
            curr = curr->next;
            m[head] = curr;
            head = head->next;
        }
        
        Node *newhead = pre->next;
        while(prehead){
            Node *t = prehead->random;
            if(t)
                newhead->random = m[t];
            else
                newhead->random = nullptr;
            prehead = prehead->next;
            newhead = newhead->next;
        }
        return pre->next;
    }
};