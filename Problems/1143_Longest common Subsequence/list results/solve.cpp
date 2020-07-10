#include"multitask.h"

int Solution::longestCommonSubsequence(string text1, string text2) {
    if (text1.empty() || text2.empty()) return 0;
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
    return table[text1.size()][text2.size()];
}

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

int Solution::longestcommonsubstring(string text1, string text2) {
    if (text1.empty() || text2.empty()) return 0;
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
    return m;
}

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