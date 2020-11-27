## 题目
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

 

Example 1:

Input: s = "3+2*2"
Output: 7

## 解法

无括号，只有+，-，*，、\/和空格，需要stack记录上一步操作是什么，方便*,\/法运算使用上一步结果
给第一个数加+号使得第一个数形式一致

**hint：当没有思路时不妨举个例子看看。+3和+3*4需要怎么记录**

```C++
class Solution {
public:
    int calculate(string s) {
        int num=0;
        char sign='+';
        stack<int> st;
        for(int i=0;i<s.size();i++){
            
            if(isdigit(s[i])){
                num = num*10+(s[i]-'0');
            }
            
            
            if((!isdigit(s[i])&&s[i]!=' ') || i==s.size()-1){
                int pre;
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
                sign=s[i];//---------更新
                num=0;
            }
        }
        int res=0;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};
```
