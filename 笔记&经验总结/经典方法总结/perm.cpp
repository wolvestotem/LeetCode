#include"leetcode.h"

bool perm(vector<int>& nums) {
	int i;
	for (i = nums.size()-2; i>=0; i--) {
		if (nums[i] < nums[i + 1])
			break;
	}//nums[i]最后一个升序
	if (i == -1)
		return false;
	int k;
	for (k = i+1; k < nums.size(); k++) {
		if (nums[k] <= nums[i]) {
			break;
		}//nums[i]右边大于的最小值
	}
	k--;//必须
	swap(nums[i], nums[k]);
	reverse(nums.begin() + i + 1, nums.end());
	return true;
}

int main(){
    vector<int> nums={1,2,3,4};
    for(int i=0;i<nums.size();i++){
        cout<<nums[i];
    }
    cout<<endl;
    //原始sort升序
    while(perm(nums)){//next_permutation(nums.begin(),nums.end())
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<' ';
        }
        cout<<endl;
    }
}
