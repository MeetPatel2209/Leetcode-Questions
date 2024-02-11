class Solution {
public:
    vector<vector<vector<int>>> dp;
    int countCherry(vector<vector<int>>& grid,int n,int m,int x1,int y1,int x2,int y2) {
        if(x1 == n && x2 == n) {
            return 0;
        }
        if(dp[x1][y1][y2] != -1) {
            return dp[x1][y1][y2];
        }
        int ans = INT_MIN;
        for(int i=-1;i<=1;i++) {
            for(int j=-1;j<=1;j++) {
                int yn1 = y1+i;
                int yn2 = y2+j;
                if(yn1>=0 && yn2>=0 && yn1<m && yn2<m) {
                    ans = max(ans,countCherry(grid,n,m,x1+1,yn1,x2+1,yn2));
                } 
            }
        }
        return dp[x1][y1][y2] = ans + (y1 == y2 ? grid[x1][y1] : grid[x1][y1] + grid[x2][y2]);
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        int ans = countCherry(grid,n,m,0,0,0,m-1);
        return ans;
    }
};