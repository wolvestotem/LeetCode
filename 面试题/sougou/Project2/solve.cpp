#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int solve(string s) {
	int n = s.size();
	vector<int> num(n, 0);
	num[0] = 1;
	for (int i = 1; i < n; i++) {
		if (s[0] == s[i]) {
			num[i] = num[i - 1] - 1>0? num[i - 1] - 1:0;
		}
		else {
			num[i] = num[i - 1] + 1;
		}
	}
	return num[n - 1];
}

int main() {
	
	string s;
	cin >> s;
	if (s.empty()) cout << 0;
	else {
		int x = solve(s);
		cout << x;
	}

}