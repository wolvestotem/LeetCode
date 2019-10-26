#include"two_sum.h"

int main() {
	vector<int> numbers = { 1,2,3,4,654,3,23,7,16 };
	int target = 7;
	Two_Sum object;
	vector<int> result;
	result = object.twosum(numbers, target);
	return(0);
}