#include"../leetcode.h"

class Solution{
public:
    string dfs(string& nums, vector<int>& fac,int k,int n){
        string res;
        vector<int> visit(n,0);
        for(int i=0;i<n;i++){
            int cnt = fac[n-i];
            for(int j=0;j<n;j++){
                if(visit[j])
                    continue;
                if(k>cnt){
                    k-=cnt;
                    continue;
                }
                // if(visit[j])
                //     continue;
                res.push_back(nums[j]);
                visit[j]=1;
                break;
            }
        }
        return res;
    }
    
    
    string getPermutation(int n, int k){
        vector<int> fac(n+1,1);
        for(int i=2;i<=n;i++){
            fac[i]=fac[i-1]*(i-1);
        }
        string nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i+'0');
        }
        string res = dfs(nums,fac,k,n);
        return res;
    }
};