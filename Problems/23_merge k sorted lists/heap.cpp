#include"../leetcode.h"

// bool compare(ListNode* a, ListNode *b){
//     return a->val>b->val;
// }

class Solution{
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.empty()) return nullptr;
        ListNode *pre = new ListNode(0);
        ListNode *curr(pre);
        vector<ListNode*> v;
        
        //lambda函数
        auto compare = [](ListNode* a, ListNode *b){return a->val>b->val;};

        for(auto pointer:lists){
            if(pointer)
                v.push_back(pointer);
        }
        if(v.empty()) return nullptr;
        make_heap(v.begin(),v.end(),compare);
        while(v.size()>1){
            curr->next = v.front();
            curr = curr->next;
            ListNode *tem = v.front();
            pop_heap(v.begin(),v.end(),compare);v.pop_back();
            tem = tem->next;
            if(tem){
                v.push_back(tem);
                push_heap(v.begin(),v.end(),compare);
            }
        }
        curr->next = v.front();
        return pre->next;
    } 
};