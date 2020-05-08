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
	int k;
	ll x;
	cin >> x >> k;
	ll sum = 0;
	int i = 0;
	while (sum < x) {
		sum += pow(2, i);
		i++;//i 层
	}
	if (k >= i)
		cout << -1 << endl;
	else {
		ll code = x >> (i - k);
		cout << code << endl;
	}

}



int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}