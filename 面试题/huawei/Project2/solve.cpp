#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void solve(vector<int>& nums) {
	unordered_map<int, int> m;
	for (auto num : nums) {
		m[num]++;
	}
	vector<int> res;
	for (auto p : m) {
		if (p.second == 1)
			res.push_back(p.first);
	}
	for (auto r : res)
		cout << r << '\t';
}

int main() {
	int t;
	cin >> t;
	vector<int> nums;
	while (t--) {
		int input;
		cin >> input;
		nums.push_back(input);
	}
	solve(nums);
}