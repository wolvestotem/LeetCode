#include"leetcode.h"
#define ll long long

void conclude();
int main(){
    conclude();
}

void conclude(){
    //-------------------------------------string char
    //isspace isdigit isalpha + char
    string s=" is 121234";
    int i=0;
    while(isdigit(s[i])){
        cout<<s[i];
        i++;
    }
    //atoi itoa---int and char*
    char num[22];
    int n = atoi(num);
    itoa(n,num,10);

    //stoi stod to_string----string
    string s1="1234";
    string s2="a34d";
    int n1=stoi(s1,nullptr,10);
    int n2=stoi(s2,nullptr,16);
    int n=100;
    string s=to_string(n);

    unsigned int l = s.size();//unsigned int!!! 和int比较时需要注意负数问题
    //或者
    int l =s.size();//强制类型转换为int，再比较
    
}