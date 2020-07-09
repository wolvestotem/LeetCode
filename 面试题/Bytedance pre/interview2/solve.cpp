#include <iostream>
#include<vector>
using namespace std;

int right_inv(vector<int>& input) {
    int left(0), right(input.size());
    int mid;
    while (left < right) {
        mid = (left + right) >> 1;
        if (input[mid] == 0) {
            left = mid + 1;
        }
        else if (input[mid] < 0) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left;
}

int left_inv(vector<int>& input) {
    int left(0), right(input.size());
    int mid;
    while (left < right) {
        mid = (left + right) >> 1;
        if (input[mid] == 0) {
            right = mid;
        }
        else if (input[mid] < 0) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left - 1;
}

int main() {

    int n, tem;
    char j;
    cin >> n;
    vector<int> input;
    while (n--) {
        cin >> tem;
        cin >> j;
        input.push_back(tem);
    }
    for (int c : input)
        cout << c << ' ';
    cout << endl;
    int negative = left_inv(input);
    int positive = right_inv(input);
    if (negative < 0)
        cout << "Negative" << -1 << endl;
    else
        cout << "Negative" << negative << endl;
    if (positive == input.size())
        cout << "Positive" << -1 << endl;
    else
        cout << "Positive" << positive+1 << endl;
}