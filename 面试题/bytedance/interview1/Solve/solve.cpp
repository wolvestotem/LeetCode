#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>


using namespace std;

//void solve(vector<int>& input, int N, int M) {
//	int min_ = INT_MAX;
//	int max_ = 0;
//	for (int i : input) {
//		if (i < min_)
//			min_ = i;
//		if (i > max_)
//			max_ = i;
//	}
//	if (max_ - min_ > 2 * M)
//		cout << -1;
//	else {
//		int l, h;
//		l = max_ - M;
//		h = min_ + M;
//		if (l < 0)
//			l = 0;
//		cout << l << ' ' << h;
//	}
//}

bool compare(pair<string, int> a, pair<string, int> b) {
	return a.first < b.first;
}

void sol(string input) {
	unordered_set<char> s;
	for (auto c : input)
		s.insert(c);
	int length = s.size();
	unordered_map<char, int> m;
	vector<pair<string,int>> dictsort;
	int right = 0, left = 0;
	while (right < input.size()) {
		m[input[right]]++;
		
		right++;
		while (m.size() == length) {
			m[input[left]]--;
			if (m[input[left]] == 0) {
				m.erase(input[left]);
				
			}
			string sub = input.substr(left, right - left);
			dictsort.push_back(make_pair(sub, left));
			left++;
		}

	}

	sort(dictsort.begin(), dictsort.end(), compare);
	cout << dictsort[0].second << dictsort[0].first.size();
}

int main() {
	/*int N, M;
	cin >> N >> M;
	int t = N;
	vector<int> input(N, 0);
	while (t--) {
		int i;
		cin >> i;
		input[N - t - 1] = i;
	}*/
	//solve(input, N, M);
	
	string input;
	cin >> input;
	sol(input);
}