### topological sort

维护一个入度数组和出度邻接表，使用queue维护一个入度为零的node集合
可以sort按照依赖关系输出，可以判断DAG是否有环

## 判断途中是否有环
### 无向图

算法1：
我们知道对于环1-2-3-4-1，每个节点的度都是2，基于此我们有如下算法（这是类似于有向图的拓扑排序）：

    求出图中所有顶点的度，
    删除图中所有度<=1的顶点以及与该顶点相关的边，把与这些边相关的顶点的度减一
    如果还有度<=1的顶点重复步骤2
    最后如果还存在未被删除的顶点，则表示有环；否则没有环

时间复杂度为O（E+V），其中E、V分别为图中边和顶点的数目，这个算法我们稍后分析算法3的时候再分析。


算法 2：
我们按照算法导论22.3节深度优先搜索中，对每个节点分为三种状态，白、灰、黑。开始时所有节点都是白色，当开始访问某个节点时该节点变为灰色，当该节点的所有邻接点都访问完，该节点颜色变为黑色。那么我们的算法则为：**如果遍历的过程中发现某个节点有一条边指向颜色为灰的节点，那么存在环。**

```C++
void dfsVisit(vector<vector<int> >&graph, int node, vector<int>&visit,
               vector<int>&father)
{
    int n = graph.size();
    visit[node] = 1;
    //cout<<node<<"-\n";
    for(int i = 0; i < n; i++)
        if(i != node && graph[node][i] != INT_MAX)
        {
            if(visit[i] == 1 && i != father[node])//找到一个环
            {
                int tmp = node;
                cout<<"cycle: ";
                while(tmp != i)
                {
                    cout<<tmp<<"->";
                    tmp = father[tmp];
                }
                cout<<tmp<<endl;
            }
            else if(visit[i] == 0)
            {
                father[i] = node;
                dfsVisit(graph, i, visit, father);
            }
        }
    visit[node] = 2;
}
 
void dfs(vector<vector<int> >&graph)
{
    int n = graph.size();
    vector<int> visit(n, 0); //visit按照算法导论22.3节分为三种状态
    vector<int> father(n, -1);// father[i] 记录遍历过程中i的父节点
    for(int i = 0; i < n; i++)
        if(visit[i] == 0)
            dfsVisit(graph, i, visit, father);
```
O(E+V)

### Directed graph

算法1. Topological sort
算法2. DFS求环