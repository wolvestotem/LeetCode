#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int solve(vector<int>& weight, vector<int>& value, int W) {
	int n = weight.size();
	vector<vector<int>> table(n + 1, vector<int>(W + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int w = 1; w <= W; w++) {
			if (w - weight[i - 1] < 0) {
				table[i][w] =  table[i - 1][w];
			}
			else {
				table[i][w] = max(table[i - 1][w - weight[i - 1]] + value[i - 1], table[i - 1][w]);
			}
		}
	}
	return table[n][W];
}


class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
};
void BFS(TreeNode* root) {
	if (!root) return;
	queue<TreeNode*> q;
	q.push(root);
	TreeNode* inter;
	while (!q.empty()){
		inter = q.front();
		cout << inter->val;
		if (inter->left) q.push(inter->left);
		if (inter->right) q.push(inter->right);
	}
}

void DFS(TreeNode* root) {
	if (!root) return;
	cout << root->val;
	DFS(root->left);
	DFS(root->right);
}

int main() {

}