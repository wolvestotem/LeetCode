#include<vector>
#include<iostream>
#include<queue>

using namespace std;

void solve1(int len, string input) {
	int st=len-1, ed=0;
	int i;
	bool haveM = false;
	for (i = 0; i < len; i++) {
		if (input[i] == 'M')
			haveM = true;
		if (haveM && input[i] == 'T')
			break;
	}
	st = i + 1;
	bool haveT = false;
	for (i = len - 1; i >= 0; i--) {
		if (input[i] == 'T')
			haveT = true;
		if (haveT && input[i] == 'M')
			break;
	}
	ed = i - 1;
	if (ed < st)
		cout << "";
	else {
		string res = input.substr(st, ed - st + 1);
		cout << res;
	}

}

void solve2(int n, vector<vector<int>>& map) {
	vector<int> occu(n + 1, -1);
	vector<int> res(n + 1, -1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (occu[map[i][j]] == -1) {
				occu[map[i][j]] = 1;
				res[i] = map[i][j];
				break;
			}
			
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i] << ' ';
	}
}

void solve3(int n, int x, int y, vector<vector<int>>& map) {
	queue < int> q;
	vector<int> visit(n + 1, 0);
	q.push(y);
	visit[y] = 1;
	int len = 0;
	int inter;
	int ext=0,sidex=0;
	while (!q.empty()) {
		
		int s = q.size();
		while (s--) {
			inter = q.front();
			q.pop();
			if (inter == x) {
				sidex = len;
				continue;
				/*if (q.empty())
					break;*/
			}
			bool leaf = true;
			for (auto node : map[inter]) {
				if (!visit[node]) {
					leaf = false;
					q.push(node);
					visit[node] = 1;
				}
			}
			if (leaf)
				ext = len;
		}
		len++;
	}
	cout << ext ;
}

int main() {
	//int len;
	//string input;
	//cin >> len;
	//cin >> input;
	////cout << len << input;
	//solve1(len, input);
	//-----------------------------
	/*int n;
	cin >> n;
	vector<vector<int>> map(n+1, vector<int>(n+1, 0));
	int in;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> in;
			map[i][j] = in;
		}
	}
	solve2(n, map);*/
	//-------------------------------
	int n, x, y;
	cin >> n >> x >> y;
	vector<vector<int>> map(n + 1, vector<int>(0, 0));
	int u, v;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		map[u].push_back(v);
		map[v].push_back(u);
	}
	solve3(n, x, y, map);
}