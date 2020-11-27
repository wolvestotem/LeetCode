## 题目

980. Unique Paths III

On a 2-dimensional grid, there are 4 types of squares:

    1 represents the starting square.  There is exactly one starting square.
    2 represents the ending square.  There is exactly one ending square.
    0 represents empty squares we can walk over.
    -1 represents obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

## 题解

经典四方向问题,使用backtracking做。
明确路径（grid），可选列表(grid)，截止条件
**做出选择后，再撤销选择**
用地图上数值标记已经走过的路径，走过后再还原值
截止条件中注意边界检测

```C++
class Solution {
    int res=0;
    int count=0;
public:
    void dfs(vector<vector<int>>& grid, int c, int x, int y){
        int m=grid.size();
        int n=grid[0].size();
        if(x<0 || x>=m || y<0 || y>=n){
            return;
        }
        if(grid[x][y]==2){
            if(c==count){
                res++;
            }
                return;
        }
        if(grid[x][y]==-1)
            return;
        if(grid[x][y]==0){
            c++;
            grid[x][y]=-1;
            dfs(grid,c,x-1,y);
            dfs(grid,c,x+1,y);
            dfs(grid,c,x,y-1);
            dfs(grid,c,x,y+1);
            grid[x][y]=0;
        }
        if(grid[x][y]==1){
            grid[x][y]=-1;
            dfs(grid,c,x-1,y);
            dfs(grid,c,x+1,y);
            dfs(grid,c,x,y-1);
            dfs(grid,c,x,y+1);
            grid[x][y]=1;
        }
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        // int count=0;
        int x,y;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0)
                    count++;//#0
                if(grid[i][j]==1){
                    x=i;
                    y=j;
                }
            }
        }
        dfs(grid,0,x,y);
        return res;
    }
};
```
