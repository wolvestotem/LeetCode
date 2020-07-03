#include <iostream>
#include<vector>
using namespace std;
struct Treenode {
    int x;
    Treenode* left, * right;
    Treenode(int n) :x(n) {}
};
Treenode* build(vector<int>& pre, vector<int>& in, int& pos, int inL, int inR) {
    if (pos >= pre.size()) return nullptr;
    Treenode* root = new Treenode(pre[pos]);
    int i;
    for (i = 0; i < in.size(); i++) {
        if (in[i] == pre[pos])
            break;
    }
    if (i > inL) root->left = build(pre, in, ++pos, inL, i - 1);
    if (i < inR) root->right = build(pre, in, ++pos, i + 1, inR);
    return root;
}
vector<int> res;
void solve(Treenode* root) {
    if (!root)
        return;
    solve(root->left);
    solve(root->right);
    res.push_back(root->x);
}
int main() {
    //int a;
    //cin >> a;
    //cout << a << endl;
    int n, t;
    cin >> n;
    int tem = n;
    vector<int> pre(n, 0);
    vector<int> in(n, 0);
    while (tem--) {
        cin >> t;
        pre.push_back(t);
    }
    tem = n;
    while (tem--) {
        cin >> t;
        in.push_back(t);
    }
    Treenode* root;
    int pos = 0;
    root = build(pre, in, pos, 0, n - 1);
    solve(root);
    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }

    //cout << "Hello World!" << endl;
}