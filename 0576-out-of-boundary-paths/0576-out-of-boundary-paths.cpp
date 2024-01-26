class Solution {
public:
    int mod = pow(10,9) + 7;
    int moves(int m,int n,int r,int c,int maxMove,vector<vector<vector<int>>> &dp) {
        if(r<0 || r>=m || c<0 || c>=n) {
            return 1;
        }
        if(maxMove == 0) {
            return 0;
        }
        if(dp[r][c][maxMove] != -1) {
            return dp[r][c][maxMove] % mod;
        }
        int delR[] = {-1,0,+1,0};
        int delC[] = {0,-1,0,+1};
        int ans = 0;
        for(int i=0;i<4;i++) {
            int rn = r+delR[i];
            int cn = c+delC[i];
            ans= (ans%mod+moves(m,n,rn,cn,maxMove-1,dp)%mod);
        }
        return dp[r][c][maxMove] = ans%mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return moves(m,n,startRow,startColumn,maxMove,dp);
    }
};