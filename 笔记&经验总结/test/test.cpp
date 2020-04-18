#include"leetcode.h"

void solve();
int main() {
	solve();
}

bool myfunc(const int i, const int j) {
	return i%5 > j%5;
}

void solve() {
	string str1("hello");
	string str2(str1.begin(), str1.end() - 1);
	str2 = "hello ";
	str2 += "nice job;";
	if (str2.find(str1) != string::npos)
		cout << "found" << endl;
	reverse(str2.begin(), str2.begin() + 3);
	reverse(str2.begin() + 3, str2.end());
	reverse(str2.begin(), str2.end());
	cout << str2 << '\t' << str1 << endl;

	vector<int> vec(10, 0);
	vec[5] = 10;
	if (find(vec.begin(), vec.begin() + 6, 10) != vec.begin() + 6)
		cout << "found the result" << endl;
	else
		cout << "There is not result";

	unordered_map<int, int> m;
	for (int i = 0; i < vec.size(); i++) {
		m[vec[i]] = i;
	}
	if (m.find(10) != m.end())
		cout << "found" << endl;
	else
		cout << "not found" << endl;

	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		v.push_back(i);
	}
	reverse(v.begin(), v.end());
	//sort(v.begin(), v.end(),myfunc);
	sort(v.begin(), v.end());
	v.insert(v.begin() + 1, 10000);
	v.erase(v.begin() + 1, v.begin() + 3);
	v.resize(distance(v.begin(),unique(v.begin(), v.end())));
	v.erase(v.begin() + 2);
	int pos = distance(v.begin(), lower_bound(v.begin(), v.end(), 2));
	cout << pos << endl;
	v.insert(v.begin() + pos, 2);
	reverse(v.begin(), v.begin() + 3);
	reverse(v.begin() + 3, v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\t';
	cout << endl;
	
	string str("Please, replace the vowels in this sentence by asterisks.");
	int found = str.find_first_of("aeiou");
	while (found != string::npos)
	{
		str[found] = '*';
		found = str.find_first_of("aeiou", found);
	}
	std::cout << str << '\n';

	int num = 10;
	char p[100];
	itoa(num, p, 10);
	string str(p);
	cout << p << endl;
}


