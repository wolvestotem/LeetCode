#include<vector>
#include<iostream>
#include<string>
	
using namespace std;

int main() {
	vector<int> joker{1,2,3,4,5};
	int ca=joker.capacity();
	cout << joker[1] << endl << ca;
}