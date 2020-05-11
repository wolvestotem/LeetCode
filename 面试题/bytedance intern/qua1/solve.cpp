#pragma once
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
#include<iostream>
#include<unordered_map>

using namespace std;
#define ll long long

void solve();
void solve2();
void solve4();
string S;
ll yushu = 835672545;
vector<pair<int, string>> oper;
void maktable();
vector<vector<int>> dp;

int main() {
	cin >> S;
	dp.resize(S.size(), vector<int>(S.size(), 0));
	int t;
	cin >> t;
	while (t--) {
		solve4();
	}
}

void maktable() {
	int n = S.size();
	vector<int> table(26,0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j >= i) {

			}
		}
	}
}

void solve4() {
	int state;
	cin >> state;
	if (state == 1) {
		int pos;
		char c;
		cin >> pos >> c;
		S[pos - 1] = c;
	}
	vector<int> table(26, 0);
	if (state == 2) {
		int l, r;
		cin >> l >> r;
		for (int i = l - 1; i < r; i++) {
			table[S[i] - 'a']++;
		}
		int num = 0;
		for (int j = 0; j < table.size(); j++) {
			if (table[j]>1)
				num++;
		}
		cout << num << endl;
	}
}

//void solve2() {
//	string text;
//	cin >> text;
//	int N;
//	cin >> N;
//	unordered_map<string, int> m;
//	string tem;
//	int maxlen = 0;
//	while (N--) {
//		cin >> tem;
//		m[tem] = 1;
//		int len = tem.size();
//		maxlen = max(maxlen, len);
//	}
//	int n = text.size();
//	vector<ll> table(n + 1, 0);
//	table[0] = 1;
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= min(i,maxlen); j++) {
//			string sub = text.substr(i-j, j);
//			if (m.find(sub) != m.end()) {//find
//				table[i] = (table[i]+table[i - j])%yushu;
//			}
//		}
//	}
//	cout << table[n] << endl;
//}





//void solve() {
//	int com;
//	cin >> com;
//	if (com == 1) {
//		string tem1;
//		cin >> tem1;
//		S.append(tem1);
//		pair<int, string> p1(1, tem1);
//		oper.push_back(p1);
//	}
//	if (com == 2) {
//		int tem2;
//		cin >> tem2;
//		string sub = S.substr(S.size() - tem2, tem2);
//		S.erase(S.end() - tem2, S.end());
//		pair<int, string> p2(2, sub);
//		oper.push_back(p2);
//	}
//	if (com == 3) {
//		int tem3;
//		cin >> tem3;
//		cout << S[tem3 - 1] << endl;
//	}
//	if (com == 4) {
//		pair<int, string> p4 = oper[oper.size() - 1];
//		if (p4.first == 1) {
//			S.erase(S.end() - p4.second.size(),S.end());
//			oper.pop_back();
//		}
//		if (p4.first == 2) {
//			S.append(p4.second);
//			oper.pop_back();
//		}
//	}
//}