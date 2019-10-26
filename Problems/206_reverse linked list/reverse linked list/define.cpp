#include"reverse.h"

int Solution::length(ListNode* head) {
	int l = 0;
	while (!head) {
		l++;
		head = head->next;
	}
	return l;
}

void Solution::swaplist(ListNode* head, int n) {
	ListNode* fi = head;
	int l = n;
	while (--l > 0) {
		fi = fi->next;
	}
	if (n > 1) {
		swap(head->val, fi->val);
		swaplist(head->next, n - 2);
	}
}

ListNode* Solution::reverseList(ListNode* head) {
	if (!head) return(nullptr);
	ListNode* fst;
	fst = head;
	int n = length(head);
	swaplist(head, n);
	return fst;
}