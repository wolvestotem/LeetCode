#pragma once
#include<vector>
#include<iostream>
#include <algorithm>

using namespace std;

class Two_Sum {
public:
	vector<int> twosum(vector<int>& nums, int target);
	Two_Sum();
	~Two_Sum();
private:
	int find_mid(vector<int>& nums);
};