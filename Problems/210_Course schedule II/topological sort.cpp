#include"../leetcode.h"

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        int V=numCourses;
        vector<vector<int>> graph(V,vector<int>{});//chu度
        vector<int> degree(V,0);//ru du
        for(auto v:prerequisites){
            graph[v[1]].push_back(v[0]);
            degree[v[0]]++;
        }
        for(int i=0;i<V;i++){
            if(degree[i]==0)
                q.push(i);
        }

        vector<int> res;
        // int count=0;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            res.push_back(t);
            // count++;
            for(auto node:graph[t]){
                if(--degree[node]==0)
                    q.push(node);
            }
        }
        if(res.size()==V)
            return res;
        else
            return vector<int>{};
    }
};