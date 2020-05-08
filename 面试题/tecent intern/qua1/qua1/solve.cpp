#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>
#include<queue>
#include<stack>
#include<math.h>

using namespace std;
#define ll long long

void solve() {
	int n;
	cin >> n;
	int a = n;
	int b = n;
	vector<int> A;
	vector<int> B;
	while (a--) {
		int tem;
		A.push_back(tem);
	}
	while (b--) {
		int tem;
		B.push_back(tem);
	}
	vector<bool> table(n, true);//a-t  b-f
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int left, right;
			left=(table[i])?
		}
	}

}



int main() {
	solve();
}