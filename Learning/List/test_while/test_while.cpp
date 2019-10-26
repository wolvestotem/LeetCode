#include<iostream>
#include<list>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

int main() {
	unordered_map<int, int> m;
	m[1] = 1;
	m[2] = 2;
	m[3] = 3;
	cout << m[5] << endl;
}
