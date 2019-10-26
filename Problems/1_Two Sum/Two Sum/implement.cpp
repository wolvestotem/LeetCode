#include"twosum.h"

int main() {
	Twosum ty;
	vector<int> numbers = { 1,2,5,7,87,54,25,12,15,4,6,13 };
	ty.print(numbers);
	int target = 112;
	vector<int> result_;
	result_ = ty.twosum(numbers, target); 
	cout << "\n RESULT:\t";
	ty.print(result_);	
}