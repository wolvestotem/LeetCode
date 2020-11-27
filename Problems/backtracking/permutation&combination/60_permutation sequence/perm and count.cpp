#include"../leetcode.h"

class Solution {
    int count=0;
    string res;
public:
    bool recur(string& nums,string& path,int k,vector<int>& visit){
        if(path.size()==nums.size()){
            count++;
            if(count==k){
                res=path;
                return true;
            }
            else
                return false;
        }
        
        for(int i=0;i<nums.size();i++){
            if(visit[i])
                continue;
            path.push_back(nums[i]);
            visit[i]=1;
            if(recur(nums,path,k,visit))
                return true;
            visit[i]=0;
            path.pop_back();
        }
        return false;
    }
    
    string getPermutation(int n, int k) {
        string nums;
        string path;
        for(int i=1;i<=n;i++){
            nums.push_back(i+'0');
        }
        vector<int> visit(n,0);
        bool x = recur(nums,path, k,visit);
        return res;
    }
};