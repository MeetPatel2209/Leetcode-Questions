class Solution {
public:
    vector<int> dp;
    int cnt(int n) {
        if(n == 0) {
            return 0;
        }
        if(n == 1) {
            return 1;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        int mini = 1e6;
        for(int i=100;i>=1;i--) {
            if(i*i<=n) mini = min(mini, 1 + cnt(n-(i*i)));
        }
        return dp[n] = mini;
    }
    
    int numSquares(int n) {
        dp.resize(n+1,-1);
        return cnt(n);
    }
};