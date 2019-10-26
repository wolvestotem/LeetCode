#include "twosum.h"

vector<int> Twosum::twosum(vector<int>& nums, int target)
{
	for (int i = 0; i < nums.size(); i++) {
		for (int j = i+1; j < nums.size(); j++) {
			if (nums[i] + nums[j] == target) {
				vector<int> result = { i,j };
				return result;
			}
		}
	}
}

void Twosum::print(vector<int>& arbitrary) {
	for (int i = 0; i < arbitrary.size(); i++) {
		printf("%d\t", arbitrary[i]);
	}
}

Twosum::Twosum()
{
	//cout << "hello world!";
}

Twosum::~Twosum()
{
	//cout << "Bye";
}