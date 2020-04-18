#include"leetcode.h"


void solve(vector<int> nums) {
	if (nums.size() == 1)
		cout << 1 << endl;
	vector<int> result(200000,0);
	for (int j = nums.size()-1; j >=0; j--) {
		int sum = 0;
		for (int k = j; k < nums.size(); k++) {
			if (k != j && nums[k] == j+1)
				sum=sum+result[k];
			if(k==j)sum++;
		}
		result[j] = sum;
	}
	for (int j = 0; j < nums.size();j++) {
		cout << result[j] << endl;
	}
}

int main() {
	int t,i;
	cin >> t;
	vector<int> nums;
	while (t--) {
		cin >> i;
		nums.push_back(i);
	}
	solve(nums);
}