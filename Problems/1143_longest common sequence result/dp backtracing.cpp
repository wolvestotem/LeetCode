#include"../leetcode.h"

class Solution {
    unordered_set<string> record_seq;
    unordered_set<string> record_str;
    void dfs_sequence(vector<vector<int>>& table, int i, int j, string path, string text1, string text2);
    void dfs_str(vector<vector<int>>& table, int i, int j, string text1);
public:
    int longestCommonSubsequence(string text1, string text2);
    vector<string> longestCommonSubsequence_result(string text1, string text2);
    int longestcommonsubstring(string text1, string text2);
    vector<string> longestcommonsubstring_result(string text1, string text2);
};

void Solution::dfs_sequence(vector<vector<int>>& table, int i, int j, string path, string text1, string text2) {
    if (i>=0 && j>=0 && table[i][j] == 0) {
        reverse(path.begin(), path.end());
        record_seq.insert(path);
        return;
    }
    if (text1[i - 1] == text2[j - 1]) {
        path.push_back(text1[i - 1]);
        dfs_sequence(table, i - 1,j - 1, path, text1, text2);
    }
    else if (table[i - 1][j] == table[i][j - 1]) {
        dfs_sequence(table, i - 1, j, path, text1, text2);
        dfs_sequence(table, i, j - 1, path, text1, text2);
    }
    else {
        (table[i - 1][j] < table[i][j - 1]) ? (dfs_sequence(table, i, j - 1, path, text1, text2)) : (dfs_sequence(table, i - 1, j, path, text1, text2));
    }
}

vector<string> Solution::longestCommonSubsequence_result(string text1, string text2) {
    vector<string> res;
    if (text1.empty() || text2.empty()) return res;
    vector<vector<int>> table(text1.size() + 1, vector<int>(text2.size() + 1, 0));

    for (int i = 1; i <= text1.size(); i++) {
        for (int j = 1; j <= text2.size(); j++) {
            if (text1[i - 1] == text2[j - 1])
                //注意text index要变化
                table[i][j] = table[i - 1][j - 1] + 1;
            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }
    if (table[text1.size()][text2.size()] == 0) return res;
    string path;
    dfs_sequence(table, text1.size(), text2.size(), path, text1, text2);
    for (auto i : record_seq)
        res.push_back(i);
    return res;
}