#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int>& num, int l, int r) {
	int pivot = num[r];
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (num[j] < pivot) {
			i++;
			swap(num[i], num[j]);
		}
	}
	swap(num[i + 1], num[r]);
	return (i + 1);
}

int func(std::vector<int>& num, int k){
	int target = num.size() - k ;
	int l = 0;
	int r = num.size() - 1;
	while (l<=r) {
		int pivot = partition(num, l, r);
		if (pivot == target) {
			return num[pivot];
		}
		else if (pivot < target) {
			l = pivot + 1;
		}
		else {
			r = pivot - 1;
		}
	}
	return -1;
}

int main() {
	vector<int> num = { 2,3,4,5,6,-1,-2,10 };
	int res = func(num, 3);
	cout << res;
}