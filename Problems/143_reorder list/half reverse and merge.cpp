#include"../leetcode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
    ListNode* reverse(ListNode* head)
    {
        ListNode *cur = head, *prev = nullptr;
        while(cur)
        {
            auto nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        auto slow = dummy, fast = dummy;
        while(fast!= nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //奇数是中间，偶数是中间的左边 
        auto left = head, right = slow->next;//左边的多右边少
        slow->next = nullptr;
        right = reverse(right);
        auto pt = dummy;
        while(left || right)
        {
            if(left)
            {
                dummy->next = left;
                left = left->next;
                dummy = dummy->next;
            }
            if(right)
            {
                dummy->next = right;
                right = right->next;
                dummy = dummy->next;
            }
        }
    }
};
