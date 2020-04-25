#include<vector>
#include<iostream>
#include<string>
using namespace std;

string solve(string input) {
	vector<int> map(128, 0);
	string output;
	for (int i = 0; i < input.size(); i++) {
		if (map[input[i]] == 0) {
			map[input[i]]++;
			output.push_back(input[i]);
		}
	}
	return output;
}

int main() {
	string input,output;
	while (cin >> input) {
		output = solve(input);
		cout << output << endl;
	}
}