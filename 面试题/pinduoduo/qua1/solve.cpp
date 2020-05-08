#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

//void solve(vector<int>& nums) {
//	sort(nums.begin(), nums.end());
//	vector<int> tem(nums.begin(),unique(nums.begin(), nums.end()));
//	unordered_map<int, int> m;
//}

//bool exist(vector<int>nums, int t) {
//	vector<int> table(nums.size(), 0);
//
//}

//void solve() {
//	int n,t;
//	cin >> n;
//	vector<int> nums(n, 0);
//	int sum = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> t;
//		sum += t;
//		nums[i] = t;
//	}
//	
//	if (sum % 4 != 0) {
//		cout << "No" << endl;
//		return;
//	}
//	int tem = sum / 4;
//	sort(nums.begin(), nums.end());
//	if (nums[nums.size() - 1] > tem) {
//		cout << "No" << endl;
//		return;
//	}
//	
//}
#define ll long long

//void solve() {
//	ll A, B, N;
//	cin >> A >> B >> N;
//	if (((A % 3) == 0) && ((B % 3) == 0)){
//		cout << "YES" << endl;
//		return;
//	}
//	vector<ll> nums(10, 0);
//	nums[0] = A; nums[1] = B;
//	for (int i = 2; i < nums.size(); i++) {
//		nums[i] = nums[i - 1] + nums[i - 2];
//	}
//	int index = 0;
//	for (int i = 0; i < nums.size(); i++) {
//		if (nums[i] % 3 == 0)
//			index = i;
//	}
//	if (((N - index) % 4) == 0)
//		cout << "YES" << endl;
//	else
//		cout << "NO" << endl;
//}
ll gcd(ll i, ll j) {
	if (i%j==0)
		return j;
	ll m = i % j;
	return gcd(j, m);
}

void solve() {
	int N;
	ll t;
	cin >> N;
	vector<ll> nums(N,0);
	for (int i = 0; i < nums.size(); i++) {
		cin >> t;
		nums[i] = t;
	}
	vector<ll> tttt(N, 0);
	vector<vector<ll>> table(N, tttt);
	ll mmm = 0;
	for (int j = 0; j < N; j++) {
		for (int i = N - 1; i >= 0; i--) {
			if (i == j)
				table[i][j] = nums[i];
			else if (j > i) {
				table[i][j] = max(gcd(table[i + 1][j], nums[i]), gcd(table[i][j - 1], nums[j]));
				ll tem = (j - i + 1) * table[i][j];
				if (tem > mmm)
					mmm = tem;
			}
			
		}
	}
	cout << mmm << endl;
}

int main() {
	solve();
	
}