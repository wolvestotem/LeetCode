## 题目
224. Basic Calculator
Hard

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2


## 解题

对于括号问题，利用递归去除括号，本题比较巧妙。使用`int& index`方法在subproblem计算时候主函数也更新index值，省去了主函数找substr传递的时间。
另外注意每个函数需要更新的值都要完成更新。

```C++
class Solution {
public:
    int recur(string& s, int& i){
        int num=0;
        int res=0;
        char sign='+';
        for(;i<s.size();i++){
            if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
            }
            if(s[i]=='('){
                num = recur(s,++i);
                i++;
            }
            if(i>=s.size()-1 || (!isdigit(s[i])&&s[i]!=' ')){
                if(sign=='+')
                    res+=num;
                else if(sign=='-')
                    res-=num;
                if(s[i]==')')
                    break;
                num=0;//------------update
                sign=s[i];
            }
        }
        return res;
    }

    int calculate(string s) {
        int index=0;
        return recur(s,index);
    }
};
```