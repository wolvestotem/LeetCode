here are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.


Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2

 

Note:

    N will be in the range [1, 100].
    K will be in the range [1, N].
    The length of times will be in the range [1, 6000].
    All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.

### DFS/BFS traverse

```C++
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if(times.empty()) return -1;
        vector<vector<pair<int,int>>> graph(N+1,vector<pair<int,int>>{});
        vector<int> visited(N+1,-1);
        visited[K]=0;
        visited[0]=0;

        for(auto line:times){
            graph[line[0]].push_back({line[1],line[2]});
        }
        stack<int> s;
        s.push(K);
        int inter;
        while(!s.empty()){
            inter=s.top();
            s.pop();
            for(auto node:graph[inter]){
                if(visited[node.first]==-1 || visited[inter]+node.second<visited[node.first]){
                    visited[node.first]=visited[inter]+node.second;
                    s.push(node.first);
                }
            }
        }
        int res=0;
        for(int i:visited){
            if(i==-1)
                return -1;
            res=max(res,i);
        }
        return res;
    }
};
```

显然可以通过从K节点开始遍历，并用visited记录节点路径长度并更新解决本问题。重点在于找到DFS时候更新visited、入栈的条件规则

