class Solution {
public:
    int compute(int i,int j,vector<int> &nums,vector<vector<int>> &dp) {
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;

        for(int k=i;k<=j;k++) {
            int burst = nums[i-1] * nums[k] * nums[j+1] + compute(i,k-1,nums,dp) + compute(k+1,j,nums,dp);
            if(burst > maxi) maxi = burst;
        }
        return dp[i][j] = maxi;

    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return compute(1,n,nums,dp); 
    }
};