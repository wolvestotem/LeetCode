#include <iostream>
#include<vector>
using namespace std;

int solve(vector<int>& input, int t) {
    int l = 0, r = input.size() - 1;

    while (l < r) {
        int mid = (l + r) >> 1;
        if (input[l] < input[r]) {
            if (t == input[mid])
                return mid;
            else if (t < input[mid])
                r = mid;
            else
                l = mid + 1;
        }
        else {
            if (input[mid] < input[r]) {
                if (t > input[mid] && t <= input[r])
                    l = mid + 1;
                else
                    r = mid;
            }
            else {

            }
        }
    }
    return l - 1;
}

int main() {
    //int a;
    //cin >> a;
    //cout << "Hello World!" << endl;
    vector<int> input{ 5,6,7,8,100,1 };
    int target = 6;
    int t = solve(input, target);
    cout << t;
}