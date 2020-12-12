#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class MinStack {
    stack<int> s;
    vector<int> mins;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (mins.empty() || mins[mins.size() - 1] >= x) {
            mins.push_back(x);
            s.push(x);
        }
        else {
            s.push(x);
        }
    }

    void pop() {
        int t = s.top();
        if (mins[mins.size() - 1] == t) {
            s.pop();
            mins.pop_back();
        }
        else {
            mins.pop_back();
        }
    }

    int top() {
        return s.top();

    }

    int min() {
        return *(mins.end() - 1);
    }
};

int main() {
    MinStack minstack;
    minstack.push(-2);
    minstack.push(0);
    minstack.push(-3);
    minstack.push(-3);
    cout << minstack.min() << endl;
    minstack.pop();
    cout << minstack.top() << endl;
    cout << minstack.min() << endl;
}