class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>> &visited) {
        visited[r][c] = 1;
        int dRow[] = {-1,0,+1,0};
        int dCol[] = {0,-1,0,+1};
        for(int i=0;i<4;i++) {
            int rn = r+dRow[i];
            int cn = c+dCol[i];
            if(rn>=0 && rn<grid.size() && cn>=0 && cn<grid[0].size() && visited[rn][cn] == 0 && grid[rn][cn] == '1') {
                dfs(rn,cn,grid,visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(visited[i][j] == 0 && grid[i][j] == '1') {
                    dfs(i,j,grid,visited);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};