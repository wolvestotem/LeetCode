#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

bool comparison(int a, int b) {
	return a > b;
}

//int solution(vector<int>& nums, int k) {
//	if (nums.size() < k || k < 0) return 0;
//	vector<int> heap(nums.begin(), nums.begin() + k);
//	//cout << heap.size();
//	make_heap(heap.begin(), heap.end(), comparison);
//	//cout << heap.front();
//	for (int i = k; i < nums.size();i++) {
//		if (nums[i] > heap.front()) {
//			cout << nums[i] << " ";
//			pop_heap(heap.begin(), heap.end()); heap.pop_back();
//			heap.push_back(nums[i]); push_heap(heap.begin(), heap.end());
//		}
//		
//	}
//	sort_heap(heap.begin(), heap.end());
//	return heap[0];
//
//}

int slide(vector<int>& nums, int lo, int hi) {
	int pivot = nums[hi];
	int i = lo - 1;
	for (int j = lo; j < hi; j++) {
		if (nums[j] < pivot) {
			i++;
			swap(nums[i], nums[j]);
		}
	}
	swap(nums[i + 1], nums[hi]);
	return i + 1;
}


int quick(vector<int>& nums, int lo, int hi, int k) {
	if (lo >= hi)
		return;
	int pivot = slide(nums, lo, hi);
	quick(nums, lo, pivot - 1);
	quick(nums, pivot + 1, hi);
}

int main() {
	vector<int> nums = { 10, 23, 56, 7, 89, 100, 20, 32 };
	int k = -1;
	if (k > nums.size() || k < 0)
		cout << "no solution" << endl;
	else {
		int result = quick(nums, 0, nums.size() - 1, k);
		cout << nums[nums.size() - k] << endl;
	}
}