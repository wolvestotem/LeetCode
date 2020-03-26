#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


//String 类方法和初始化
string one("hello");
string two(2,'$');
string three(one);
two = "hello world";
one +="hhh";
three[0] = '!';
string four(&one[1],&one[4]);

