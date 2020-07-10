#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

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