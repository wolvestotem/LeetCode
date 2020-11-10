//#include<iostream>
//#include<vector>
//
//using namespace std;
//#define ll long long
//
//void solve(int n, int m, ll q, vector<vector<int>>& map, vector<pair<int, int>>& sent) {
//	vector<int> res(n + 1, 0);
//	for (auto p : sent) {
//		int x = p.first-1;
//		int y = p.second-1;
//		for (auto row : map[y]) {
//			if (row != x)
//				res[row]++;
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		cout << res[i] << ' ';
//	}
//}
//
//int main() {
//	int n, m;
//	ll q;
//	cin >> n >> m >> q;
//	vector<vector<int>> map(m, vector<int>(1,n));
//	int t;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> t;
//			if (t == 1) {
//				map[j].push_back(i);
//			}
//		}
//	}
//	vector<pair<int, int>> sent;
//	int x, y;
//	for (int k = 0; k < q; k++) {
//		cin >> x >> y;
//		sent.push_back(make_pair(x, y));
//	}
//	/*for (int i = 0; i < m; i++) {
//		for (int s : map[i]) {
//			cout << s;
//		}
//		cout << endl;
//	}
//	cout << endl;*/
//	solve(n, m, q, map, sent);
//}



#include<iostream>
#include<vector>

using namespace std;

int main() {
	int t;
	cin >> t;

	int R, G, B;
	cin >> R >> G >> B;

	vector<int> g(G, 0);
	vector<int> r(R, 0);
	vector<int> b(B, 0);
	int in;
	for (int i = 0; i < R; i++) {
		cin >> in;
		r[i] = in;
	}
	for (int i = 0; i < G; i++) {
		cin >> in;
		g[i] = in;
	}
	for (int i = 0; i < B; i++) {
		cin >> in;
		b[i] = in;
	}

	int q; 
	cin >> q;

}