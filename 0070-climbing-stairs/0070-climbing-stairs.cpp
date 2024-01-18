class Solution {
public:
    vector<int> dp;
    int countSteps(int n) {
        if(n == 0) {
            return 1;
        }
        if(n<0) {
            return 0;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = countSteps(n-1) + countSteps(n-2);
    }
    
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        return countSteps(n);
    }
};