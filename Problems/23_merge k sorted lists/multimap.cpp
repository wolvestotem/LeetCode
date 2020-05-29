#include"../leetcode.h"

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
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;//平凡情况讨论
        multimap<int,ListNode*> m;
        ListNode *pre = new ListNode(0);
        ListNode *curr(pre);
        for(auto pointer:lists){
            if(pointer)//平凡情况讨论
                m.emplace(pointer->val, pointer);
        }
        if(m.size()==0)//平凡情况讨论
            return nullptr;
        while(m.size()>1){//应该明确更新的变量：curr, m, listnode
            ListNode* tem(m.begin()->second);
            curr->next = tem;
            curr = curr->next;
            m.erase(m.begin());
            tem = tem->next;
            if(tem)
                m.emplace(tem->val, tem);
        }
        curr->next = m.begin()->second;
        return pre->next;
    }
};