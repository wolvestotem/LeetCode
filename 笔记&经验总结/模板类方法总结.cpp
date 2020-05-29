#include"leetcode.h"


bool myfunc(const int i, const int j) {
	return i%5 > j%5;
}

int main(){
    //------------------------------------------所有数据结构 删插改查 操作
    vector<int> v_;
    v_.push_back(1);
    v_.pop_back();
    stack<int> s;
    s.push(1);
    s.pop();
    s.top();
    queue<int> q;
    q.push(1);
    q.pop();
    q.front();
    q.back();
    string str;
    string s_;
    str.push_back('c');//push_back只能是char类型
    str.pop_back();
    str.append("hello");//append丰富很多
    str.append(10,'.');
    str.append(s_.begin(),s_.end());

    
    //----------------------------------------------unordered_map/map traverse
    unordered_map<int,int> m;
    for (auto i : m) 
        cout << i.first << "    " << i.second //element
             << endl; 
    for(auto i=m.begin();i!=m.end();i++)
        cout << i->first << "      " << i->second //iterator
             << endl; 

    
    //-------------------------------------find function (string algorithm hash_table)
    //string.find()
    string str1("hello world");
    string str2(str1.begin(),str1.end()-1);
    if(str1.find(str2) != string::npos)
        cout<<"found, return the rank of the first char of the match"<<endl;
    //algorithm find
    vector<int> vec(10,0);
    vec[5]=10;
    if(find(vec.begin(),vec.begin()+6,10)!=vec.begin()+6)//左开右闭
        cout<<"found the result"<<endl;//pick
    else
        cout<<"There is not result";
        
    //unordered_map find
    unordered_map<int,int> m;
    for(int i=0;i<vec.size();i++){
        m[vec[i]]=i;
    }
    if(m.find(10)!=m.end())
    cout<<"found"<<endl;
    else
    cout << "not found"<<endl;
    
    //----------------------------------------------常用algorithm function
    vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	reverse(v.begin(), v.end());
	sort(v.begin(), v.end(),myfunc);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\t';	reverse(v.begin(), v.end());
	sort(v.begin(), v.end(),myfunc);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\t';
    swap(v[1],v[2]);
    vector<int>::iterator low,hi;
    low = lower_bound(v.begin(),v.end(),20);
    hi = upper_bound(v.begin(),v.end(),20);
    cout<<distance(v.begin(),low)<<distance(v.begin(),hi)<<endl;
    // 10 10 10 20 20 20 30 30--->low->3  hi->6
    swap(v[1],v[2]);
    vector<int>::iterator low,hi;
    low = lower_bound(v.begin(),v.end(),20);
    hi = upper_bound(v.begin(),v.end(),20);
    cout<<distance(v.begin(),low)<<distance(v.begin(),hi)<<endl;
    // 10 10 10 20 20 20 30 30--->low->3  hi->6
}