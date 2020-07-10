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

void Solution::dfs_str(vector<vector<int>>& table, int i, int j, string text1) {
    string path;
    while (i>=0 && j>=0 && table[i][j]) {
        path.push_back(text1[i]);
        i--;
        j--;
    }
    reverse(path.begin(), path.end());
    record_str.insert(path);
}

vector<string> Solution::longestcommonsubstring_result(string text1, string text2) {
    vector<string> res;
    if (text1.empty() || text2.empty()) return res;
    vector<vector<int>> table(text1.size(), vector<int>(text2.size(), 0));
    for (int i = 0; i < text1.size(); i++) {
        if (text1[i] == text2[0])
            table[i][0] = 1;
    }
    for (int j = 0; j < text2.size(); j++) {
        if (text1[0] == text2[j])
            table[0][j] = 1;
    }
    int m = 0;
    for (int i = 1; i < text1.size(); i++) {
        for (int j = 1; j < text2.size(); j++) {
            if (text1[i] == text2[j]) {
                table[i][j] = table[i - 1][j - 1] + 1;
                m = max(m, table[i][j]);
            }
        }
    }
    if (m == 0) return res;

    for (int i = 0; i < text1.size(); i++) {
        for (int j = 0; j < text2.size(); j++) {
            if (table[i][j] == m) {
                dfs_str(table, i, j, text1);
            }
        }
    }
    for (auto s : record_str)
        res.push_back(s);
    return res;
}