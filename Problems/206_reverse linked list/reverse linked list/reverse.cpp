#include"reverse.h"

int main(){
	ListNode* dummy = new ListNode(0);
	ListNode* fst = dummy;
	ListNode* result;
	for (int i = 1; i < 6; i++) {
		ListNode* header = new ListNode(i);
		dummy = dummy->next = header;
	}//---------------------------------------0,1,2,3,4,5
	Solution obj;
	result = obj.reverseList(fst);
	for (int i = 5; i >= 0; i--) {
		cout << result->val << endl;
		result = result->next;
	}
}