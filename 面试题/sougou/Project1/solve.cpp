#include<iostream>
#include<vector>

using namespace std;

void solve(vector<int>& input, int t) {
	int l = 0, r = input.size();
	int mid;
	while (l < r) {//right
		mid = (l + r) >> 1;
		if (input[mid] < t)
			l = mid + 1;
		else if (input[mid] == t)
			l = mid + 1;
		else
			r = mid;
	}
	int right = l - 1;
	l = 0;
	r = input.size();
	while (l < r) {
		mid = (l + r) >> 1;
		if (input[mid] < t)
			l = mid + 1;
		else if (input[mid] == t)
			r = mid;
		else
			r = mid;
	}
	int left = r;
	int res = right - left + 1;
	cout << res << endl;
}

int main() {
	vector<int> input{ 1,2,3,4,7,8,8,8,10,100,100,200 };
	int target = 9;
	solve(input, target);
}