#include"leetcode.h"

using namespace std;

void bubble_sort(vector<int>& nums) {//O(n^2)
	for (int i = 0; i < nums.size(); i++) {
		for (int j = i; j < nums.size(); j++) {
			if (nums[j] < nums[i])
				swap(nums[i], nums[j]);
		}
	}
}

void merge(vector<int>& nums, int lo, int hi) {
	int mi = (lo + hi) >> 1;
	vector<int> left(nums.begin() + lo, nums.begin() + mi+1);
	vector<int> right(nums.begin() + mi + 1, nums.begin() + hi+1);
	int l = 0; 
	int r = 0;
	left.insert(left.end(), INT_MAX);
	right.insert(right.end(), INT_MAX);
	for (int i = lo; i <= hi; i++) {
		if (left[l] < right[r]) {
			nums[i] = left[l];
			l++;
		}
		else {
			nums[i] = right[r];
			r++;
		}
	}
}

void merge_sort(vector<int>& nums, int lo, int hi) {
	if (lo >= hi)
		return;
	int mi = (lo + hi) >> 1;
	merge_sort(nums, lo, mi);
	merge_sort(nums, mi + 1, hi);
	merge(nums, lo, hi);
}

int partition(vector<int>& nums, int lo, int hi) {
	int pivot = nums[hi];
	int i = lo - 1;
	for (int j = lo; j < hi; j++) {
		if (nums[j] < pivot) {
			i++;
			swap(nums[i], nums[j]);
		}
	}
	swap(nums[hi], nums[i + 1]);
	return(i + 1);
}

void quick_sort(vector<int>& nums, int lo, int hi) {
	if (lo >= hi)
		return;
	int pivot = partition(nums, lo, hi);
	quick_sort(nums, lo, pivot - 1);
	quick_sort(nums, pivot + 1, hi);
}


void selection_sort(vector<int>& nums) {
	for (int i = 0; i < nums.size() - 1; i++) {
		int min = i;
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[j] < nums[min])
				min = j;
		}
		swap(nums[i], nums[min]);
	}
}


void insert_sort(vector<int>& nums) {
	for (int i = 1; i < nums.size(); i++) {
		for (int j = i; j >= 0; j--) {
			if (nums[j] < nums[j - 1])
				swap(nums[j], nums[j - 1]);
		}
	}
}

int main(){
	int n;
	vector<int> nums;
	cin >> n;
	while (n--) {
		int i;
		cin >> i;
		nums.push_back(i);
	}


	//bubble_sort(nums);//stable
	//merge_sort(nums,0,nums.size()-1);//stable
	//quick_sort(nums, 0, nums.size() - 1);//unstable
	selection_sort(nums);//unstable
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << '\t';
	}
	
}