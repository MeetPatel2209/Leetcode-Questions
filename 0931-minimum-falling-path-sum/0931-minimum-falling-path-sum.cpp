class Solution {
public:
    vector<vector<int>> dp;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        dp.resize(n+1,vector<int>(m+1,0));
        int ans = INT_MAX;
        for(int i=0;i<m;i++) {
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1;i<n;i++) {
            for(int j=0;j<m;j++) {
                int ld=1e9,rd=1e9;
                int up = matrix[i][j] + dp[i-1][j];
                if(j-1>=0) {
                    ld = matrix[i][j] + dp[i-1][j-1];
                }
                if(j+1<m) {
                    rd = matrix[i][j] + dp[i-1][j+1];
                }
                dp[i][j] = min(up,min(ld,rd));
            }
        }
        ans = dp[n-1][0];
        for(int i=1;i<m;i++) {
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};