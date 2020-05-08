#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>
#include<queue>
#include<math.h>

using namespace std;

void solve() {
	int N;
	cin >> N;
	int atemp=N;
	int btemp = N;
	vector<pair<int,int>> A;
	double min_ = 2*pow(10,9);
	while (atemp--) {
		int a, b;
		cin >> a >> b;
		pair<int, int> p(a, b);
		A.push_back(p);
	}
	while (btemp--) {
		int a, b;
		cin >> a >> b;
		for (int i = 0; i < N; i++) {
			double d = sqrt(pow((A[i].first - a),2) + pow((A[i].second - b),2));
			min_ = min(d, min_);
		}
	}
	/*int tem = min_ * 1000;
	double result = (double)tem / 1000;*/
	printf("%.3f", min_);
	cout << endl;
}



int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}