class Solution {
public:
    //set<int> st;
    int computeCost(int l,int r,vector<int> &cuts,vector<vector<int>> &dp) {
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int mini = INT_MAX;
        for(int i = l;i<=r;i++) {
            {
                int steps = cuts[r+1]-cuts[l-1] + computeCost(l,i-1,cuts,dp) + computeCost(i+1,r,cuts,dp);
                if(steps < mini) mini = steps;
            }
        }
        return dp[l][r] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return computeCost(1,c,cuts,dp);
    }
};