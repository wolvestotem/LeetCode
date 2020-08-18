#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(unsigned int n) {
	int count = 0;
	unsigned int t;

	while (n > 0) {
		t = n >> 1;
		if (n - t * 2) {
			count++;
			n = n >> 1;
		}
		else {
			n = n >> 1;
		}
	}
	cout << "n=" << count << endl;

}

int partition(vector<int>& input, int lo, int hi) {
	int pivot = input[hi];
	int i = lo - 1;
	for (int j = lo; j < hi; j++) {
		if (input[j] < pivot) {
			i++;
			swap(input[i], input[j]);
		}
	}
	swap(input[i + 1], input[hi]);
	return i + 1;
}

void sort(vector<int>& input, int lo, int hi) {
	if (lo >= hi)
		return;
	int pivot = partition(input, lo, hi);
	sort(input, lo, pivot - 1);
	sort(input, pivot + 1, hi);
}

int main() {
	unsigned int n;
	//cin >> n;
	vector<int> input{ 2,1,-1,3,9,10,-10 };
	//solve(n);
	sort(input, 0, input.size() - 1);
	for (int i : input)
		cout << i << '\t';
}