## 题目


772. 基本计算器 III

实现一个基本的计算器来计算简单的表达式字符串。

表达式字符串只包含非负整数， +, -, *, / 操作符，左括号 ( ，右括号 )和空格 。整数除法需要向下截断。

你可以假定给定的字符串总是有效的。所有的中间结果的范围为 [-2147483648, 2147483647]。

进阶：你可以在不使用内置库函数的情况下解决此问题吗？

## 题解

综合了括号递归和四则运算stack，注意数字范围溢出

```C++
class Solution {
public:
    int recur(string& s, int& i){
        long num=0;
        char sign='+';
        stack<long> st;
        for(;i<s.size();i++){
            if(isdigit(s[i])){
                num = num*10+(s[i]-'0');
            }
            if(s[i]=='('){
                num=recur(s,++i);
                i++;
            }
            if((!isdigit(s[i])&&s[i]!=' ') || i>=s.size()-1){
                long pre;
                switch(sign){
                    case('+'):
                        st.push(num);break;
                    case('-'):
                        st.push(-num);break;
                    case('*'):
                        pre=st.top();
                        st.pop();
                        st.push(pre*num);
                        break;
                    case('/'):
                        pre=st.top();
                        st.pop();
                        st.push(pre/num);
                        break;
                }
                num=0;
                sign=s[i];
                if(s[i]==')')
                    break;
            }
        }
        long res=0;
        while(!st.empty()){
            res=res+st.top();
            st.pop();
        }
        return res;
    }
    int calculate(string s) {
        int index=0;
        return recur(s,index);
    }
};
```
