#include"leetcode.h"

ListNode* reverse(ListNode* head) {
	if (!head) return nullptr;
	ListNode* curr = head;
	ListNode* pre = nullptr;
	ListNode* fu=head;
	while (fu) {
		fu = curr->next;
		curr->next = pre;
		pre = curr;
		curr = fu;
	}
	return(pre);
}
ListNode* generate(vector<int> list) {
	ListNode* curr=new ListNode(0);
	ListNode* ptr = curr;
	for (auto item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = curr->next;
	delete curr;
	return ptr;
}

int main(){
    vector<int> list = { 1,2,3,4,5,6 };
	ListNode* head;
	head = generate(list);
	head=reverse(head);
	while (head) {
		cout << head->val << ' ';
		head = head->next;
	}
	cout << endl;
}