#include"../leetcode.h"

struct compare{
    bool operator()(ListNode* &a,ListNode* &b)
        {   return a->val>b->val;
        }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*,vector<ListNode*>,compare>minh;
    for(int i=0;i<lists.size();i++)
        if(lists[i]!=NULL)
            minh.push(lists[i]);
    ListNode* temp;
    ListNode* head=NULL;
    while(minh.empty()==false)
    {
        ListNode*node=minh.top();
        minh.pop();
        
        if(node->next!=NULL)
            minh.push(node->next);
        if(head==NULL)
        {   head=node;
            temp=node;
        }
        else
        {   temp->next=node;
            temp=node;
        }
    }
    return head;
}