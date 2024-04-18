class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j,int n,int m) {
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j] == 0) return 1;
        if(grid[i][j] == -1) return 0;
        grid[i][j] = -1;
        return (dfs(grid,i+1,j,n,m) + dfs(grid,i,j+1,n,m) + dfs(grid,i-1,j,n,m) + dfs(grid,i,j-1,n,m));
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1) {
                    cnt += dfs(grid,i,j,n,m);
                }
            }
        }
        return cnt;
    }
};