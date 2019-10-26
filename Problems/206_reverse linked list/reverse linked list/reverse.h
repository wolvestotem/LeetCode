#pragma once
#include<algorithm>
#include<iostream>
#include<list>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* reverseList(ListNode* head);
	int length(ListNode* head);
	void swaplist(ListNode* head, int n);
};