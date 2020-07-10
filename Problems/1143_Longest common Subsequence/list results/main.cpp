#include"multitask.h"

int main() {
	Solution seq;
	string text1, text2;
	cin >> text1 >> text2;
	int length;
	vector<string> res;
	/*length = seq.longestCommonSubsequence(text1, text2);
	res = seq.longestCommonSubsequence_result(text1, text2);
	cout << length << endl;
	for (auto c : res)
		cout << c << '\t';*/

	Solution str;
	length = str.longestcommonsubstring(text1, text2);
	res = str.longestcommonsubstring_result(text1, text2);
	cout << length << endl;
	for (auto c : res)
		cout << c << '\t';
}