#include"two_sum.h"

Two_Sum::Two_Sum() {

}
Two_Sum::~Two_Sum() {

}

vector<int> Two_Sum::twosum(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end(), less<int>());
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << "\t";
	cout << endl;
	for (int j = 0; )
	return nums;
}

int Two_Sum::find_mid(vector<int>& nums) {
	int n = nums.size();

}