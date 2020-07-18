#include"leetcode.h"
#include<thread>
#define ll long long
void solve();
string pre;

void print(int n) {
	for(int i=0;i<n;i++)
		cout << "hello world" << i << endl;
}

class KMP {
private:
	string model;
public:
	KMP(string pat) {
		this->model = pat;
	}
};
int main() {
	solve();
}

bool comparison(const string a, const string b) {
	return a.size() < b.size();
}

string arrangeWords(string text) {
	//32
	if (text.size() == 0) return "";
	vector<string> word;
	text[0] = tolower(text[0]);
	int start(0);
	// int j=0;
	// for(int i=0;i<text.size();i++){
	//     if(i==0)
	//         word[0].push_back(tolower(text[0]));
	//     else if(isspace(text[i])){
	//         j++;
	//         word.push_back("");
	//     }
	//     else{
	//         word[j].push_back(text[i]);
	//     }
	// }
	while (text.find_first_of(" ") != string::npos) {
		int found = text.find_first_of(" ");
		text[found] = '*';
		word.push_back(text.substr(start, found - start));
		start = found + 1;
	}
	word.push_back(text.substr(start));
	stable_sort(word.begin(), word.end(), comparison);
	string result;
	for (int i = 0; i < word.size(); i++) {
		result = result + word[i];
		if (i != word.size() - 1)
			result += " ";
	}
	result[0] = toupper(result[0]);
	return result;
}

bool strfcn(char a,char b) {
	return pre.find(a) < pre.find(b);
}

bool myfunc(const int i, const int j) {
	return i%5 > j%5;
}

int lengthOfLongestSubstring(string s) {
	if (s.empty())return 0;
	int max_ = 0;
	int l;
	string sub;
	int lo = 0;
	while (true) {
		sub = s.substr(lo, 1);
		int curr = lo + 1;
		while (sub.find(s[curr]) == string::npos && curr < s.size()) {
			sub.push_back(s[curr]);
			curr++;
		}
		l = sub.size();
		if (sub.size() > max_)
			max_ = sub.size();
		lo = curr;
		if (lo >= s.size() - 1)
			break;
	}
	return max_;
}

bool perm(vector<int>& nums) {
	int i;
	for (i = nums.size()-2; i>=0; i--) {
		if (nums[i] < nums[i + 1])
			break;
	}
	if (i == -1)
		return false;
	int k;
	for (k = i+1; k < nums.size(); k++) {
		if (nums[k] <= nums[i]) {
			break;
		}
	}
	k--;
	swap(nums[i], nums[k]);
	reverse(nums.begin() + i + 1, nums.end());
	return true;
}

ListNode* generate(vector<int> l) {
	ListNode* curr=new ListNode(0);
	ListNode* ptr = curr;
	for (auto item : l) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = curr->next;
	delete curr;
	return ptr;
}

ListNode* reverse(ListNode* head) {
	if (!head) return nullptr;
	ListNode* curr = head;
	ListNode* pre = nullptr;
	ListNode* fu=head;
	while (fu) {
		fu = curr->next;
		curr->next = pre;
		pre = curr;
		curr = fu;
	}
	return(pre);
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

	string s = " a12345a";
	s[s.find("123")]='*';
	cout << s << endl;
	cout << isspace(s[0]) << endl;
	char num[22];
	int n=100;
	_itoa_s(n,num,2);
	cout << num << endl;

	vector<int> nums = {1,2,3};
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
	while (next_permutation(nums.begin(),nums.end())) {//perm(nums)
		for (int i = 0; i < nums.size(); i++) {
			cout << nums[i] << ' ';
		}
		cout << endl;
	}

	vector<int> l = { 1,2,3,4,5,6 };
	ListNode* head;
	head = generate(l);
	head=reverse(head);
	while (head) {
		cout << head->val << ' ';
		head = head->next;
	}
	cout << endl;

	string T = "abdfgichbca";
	string S = "abcdefghi";
	pre = S;
	//sort(T.begin(), T.end(), strfcn);
	cout << T << endl;
	int len;
	len = lengthOfLongestSubstring(T);
	cout << len << endl;
	len = S.find('z');
	cout << len << endl;
	S.insert(S.begin(), 2, 'M');
	S.insert(S.begin(), T.begin(), T.begin() + 1);
	cout << S << endl;
	int n_ = 33;
	cout << n_ / 10 << endl;
	int a = 100;
	int b = 0;
	cout << "a^b=" << (b ^ a ^ b) << endl;
	char c_ = 'f';
	vector<vector<int>> vv(10, vector<int>(10, 0));
	for (int i = 0; i < 10; i++) {
		cout << vv[1][i] << '\t';
	}
	cout << endl;
	cout << typeid(T).name() << endl;
	cout << typeid(c_).name() << endl;

	string num_ = "2345";
	cout << stoi(num_,nullptr,16) << endl;

	cout << (-33) % 10 << (-29) % 10 << endl;

	unordered_set<int> lookup;
	lookup.insert(4);
	lookup.insert(1);
	lookup.insert(1);
	lookup.insert(1);
	lookup.insert(2);
	for (auto i : lookup)
		cout << i << ' ';
	cout << endl;

	list<int>::iterator it;
	list<int> mylist(10, 10);
	it = mylist.begin();
	it++;
	for (auto i : mylist)
		cout << i << ' ';
	cout << endl;
	mylist.insert(it, 20);
	mylist.insert(it, 2, 5);
	for (auto j : mylist)
		cout << j << ' ';
	cout << endl;
	string result;
	result = arrangeWords("To be or not to be");
	cout << result << endl;

	int aa = 2;
	cout << ((aa - 1) >>1) << endl;

	cout << to_string(-1) << endl;

	thread th1(print, 3);
	cout << "hhh" << endl;
	th1.join();
	cout << "hi" << endl;
}


