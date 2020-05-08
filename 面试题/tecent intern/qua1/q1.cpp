#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>
#include<queue>

using namespace std;

void solve() {
	int q;
	cin >> q;
	queue<int> qu;
	string input;
	while (q--) {
		cin >> input;
		if (input == "PUSH")
			q++;
		if (isdigit(input[0])) {
			int num = stoi(input, nullptr, 10);
			qu.push(num);
		}
		if (input == "TOP") {
			if (qu.empty())
				cout << -1 << endl;
			else
				cout << qu.front() << endl;
		}
		if (input == "POP") {
			if (qu.empty())
				cout << -1 << endl;
			else
				qu.pop();
		}
		if (input == "SIZE")
			cout << qu.size() << endl;
		if (input == "CLEAR") {
			while (!qu.empty()) {
				qu.pop();
			}
		}

	}
}



int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}