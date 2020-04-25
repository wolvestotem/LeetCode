#include<vector>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

string solve1(string input) {
	vector<int> map(128, 0);
	string result;
	for (int i = 0; i < input.size(); i++) {
		if (isdigit(input[i])) {
			map[input[i]]++;
		}
	}
	for (int i = '0'; i <= '9'; i++) {
		char c = i;
		result.insert(result.end(), map[i], c);
	}
	return result;
}

bool first = true;

void solve2(vector<int>& input,int start) {
	/*for (int i = start; i < input.size(); i++)
		cout << input[i] << ' ';
	cout << endl;*/
	
	vector<int> p(input.begin() + start, input.end());
	vector<int> remain=p;
	if (p.size() == 1)
		return;

	for (int i = 0; i < p.size()-1; i++) {
		if (p[i] == 91 && p[i + 1] == 186) {
			p.erase(p.begin() + i, p.begin() + i + 2);
			p.insert(p.begin() + i, 90);
		}
		if (p[i] == 91 && p[i + 1] == 187) {
			p.erase(p.begin() + i, p.begin() + i + 2);
			p.insert(p.begin() + i, 91);
		}
	}
	if (p[p.size() - 1] != 90)
		return;
	if (p.size()-2 != p[p.size() - 2])
		return;
	else if (first) {
		remain.insert(remain.begin(), 90);
		first = false;
		for (auto i : remain)
			cout << hex << setfill('0') << setw(2) << i << ' ';
	}
	else {
		for (auto i : remain)
			cout << hex << setfill('0') << setw(2) << i << ' ';
	}
}


vector<int> solve(vector<int> input) {
	vector<int> index;

}

int main() {
	int m, k, t;
	cin >> m >> k;
	vector<int> input;
	while (m--) {
		cin >> t;
		input.push_back(t);
	}
	vector<int> solve(input);
}