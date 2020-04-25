#include"leetcode.h"

int main(){
    //----------------------------------------------String 初始化
    //string 初始化
    string one("hello");
    string two(2,'$');
    string three(one);
    two = "hello world";
    one +="hhh";
    three[0] = '!';
    string four(one.begin(),one.end()-1);
    //--------------------------------------------------string 方法
    //find_first_of  find_last_of  find_first_not_of find_last_not_of同理
    string str("Please, replace the vowels in this sentence by asterisks.");
    int found =str.find("in");
    if(found!=string::npos)
        str[found]='*';
	int found = str.find_first_of("aeiou");
	while (found != string::npos)
	{
		str[found] = '*';
		found = str.find_first_of("aeiou", found);
	}
	std::cout << str << '\n';
    //OUTPUT: Pl**s*, r*pl*c* th* v*w*ls *n th*s s*nt*nc* by *st*r*sks.

    cout << "Splitting: " << str << '\n';
    int found = str.find_last_of("/\\");
    cout << " path: " << str.substr(0,found) << '\n';//str.substr(int start_rank, int length)!!
    cout << " file: " << str.substr(found+1) << '\n';

    //OUTPUT: Splitting: /usr/bin/man
                    //path: /usr/bin
                    //file: man
    
    str="sample phrase!!";
    str.replace(str.begin(),str.begin()+6,"replace");//左开右闭


    //------------------------------------------------------vector 方法
    vector<int> v1;
    vector<int> v2(3,100);
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
    v1.insert(v1.begin()+1,100);
    //resize unique distance
    v1.resize(distance(v1.begin(),unique(v1.begin(), v1.end())));
    // 10 20 20 20 30 30 20 20 10---->10 20 30 20 10
    //sorted -> unique vector
    v2.insert(v2.begin(),2,90);
    v2.insert(v2.end(),v1.begin(),v1.begin()+1);
    for(auto i:v2)
        cout<<i<<' ';
}