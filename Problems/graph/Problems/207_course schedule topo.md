There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

 

Constraints:

    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.
    1 <= numCourses <= 10^5

```C++

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        int count=0;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            count++;
            for(auto node:graph[t]){
                if(--degree[node]==0)
                    q.push(node);
            }
        }
        if(count==V)
            return true;
        else
            return false;
    }
};

```

topological sort. Use in DAG(有向无环图)，可以判断具有依赖关系的能否走通，需要维护一个degree入度vector和queue入度为0节点