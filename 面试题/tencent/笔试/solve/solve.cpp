#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>

using namespace std;

struct Listnode
{
	int val;
	Listnode* next;
	Listnode(int x):val(x),next(nullptr){}
};

//void solve(Listnode* fir, Listnode* sec) {
//	if (!fir || !sec)
//		return;
//	Listnode* pre = new Listnode(0);
//	Listnode* curr(pre);
//	while (fir && sec) {
//		if (fir->val == sec->val) {
//			curr->next = new Listnode(fir->val);
//			fir = fir->next;
//			sec = sec->next;
//			curr = curr->next;
//		}
//		else if (fir->val < sec->val) {
//			sec = sec->next;
//		}
//		else {
//			fir = fir->next;
//		}
//	}
//	while (pre->next)
//	{
//		cout << pre->next->val << ' ';
//		pre = pre->next;
//	}
//}

//int main() {
//	int n, m;
//	Listnode* fir = new Listnode(0);
//	Listnode* sec = new Listnode(0);
//	Listnode* cfir(fir), * csec(sec);
//
//	cin >> n;
//	int infir, insec;
//	while (n--) {
//		cin >> infir;
//		cfir->next = new Listnode(infir);
//		cfir = cfir->next;
//	}
//	cin >> m;
//	while (m--) {
//		cin >> insec;
//		csec->next = new Listnode(insec);
//		csec = csec->next;
//	}
//
//	solve(fir->next, sec->next);
//}

void solve(vector<pair<int,int>>& group, vector<vector<int>>& people, vector<vector<int>>& yingshe, int m, int n, bool havezero) {
	int number = 0;
	if (!havezero) {
		cout << 1 << endl;
		return;
	}
	queue < int> q;
	for (auto i : people[0]) {
		q.push(i);
		group[i].second = 1;
		number = number + group[i].first;
	}
	while (!q.empty()) {
		int g = q.front();
		for (int j : yingshe[g]) {
			for (int k : people[j]) {
				if (group[k].second == 0) {
					q.push(k);
					number = number + group[k].first;
					group[k].second = 1;
				}
			}
		}
	}
	cout << number << endl;
}

int main() {
	int n, m;
	cin >> n >> m;
	int ori(m);
	vector<pair<int, int>> group;
	vector<vector<int>> people(n, vector<int>(0));
	vector<vector<int>> yingshe(m, vector<int>(0));
	
	bool havezero = false;
	int t, a;
	m++;
	while (m--) {
		cin >> t;
		group.emplace_back(t, 0);
		while (t--) {
			cin >> a;
			if (a == 0)
				havezero = true;
			people[a].push_back(ori-m-1);
			//yingshe[ori - m - 1].push_back(a);
		}
	}

	solve(group, people, yingshe, m, n, havezero);
}

//int main() {
//	int n, k;
//	cin >> n >> k;
//	unordered_map<string, int> m;
//	string input;
//	while (n--) {
//		cin >> input;
//		if (m.count(input))
//			m[input]++;
//		else
//			m[input] = 1;
//	}
//}

//void solve(vector<int>& input,int n) {
//	vector<int> b(input.begin(), input.end());
//	sort(b.begin(), b.end());
//	int r = n >> 1;
//	int l = r - 1;
//	for (int i : input) {
//		if (i <= b[l])
//			cout << b[r] << endl;
//		else
//			cout << b[l] << endl;
//	}
//}
//
//int main() {
//	int n,t;
//	int originn;
//	cin >> n;
//	originn = n;
//	vector<int> input;
//	while (n--) {
//		cin >> t;
//		input.push_back(t);
//	}
//	solve(input,originn);
//}