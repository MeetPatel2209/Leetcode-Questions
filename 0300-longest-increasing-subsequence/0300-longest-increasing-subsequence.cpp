class Solution {
public:
    int compute(vector<int>& nums,int index,int prev,int n,vector<vector<int>> &dp) {
        if(index == n) {
            return 0;
        }
        if(dp[index][prev+1] != -1) {
            return dp[index][prev+1];
        }
        int len = compute(nums,index+1,prev,n,dp); 
        if(prev == -1 || nums[prev]<nums[index]) {
            len = max(len, 1 + compute(nums,index+1,index,n,dp));
        }
        return dp[index][prev+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int index=0;
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return compute(nums,index,-1,n,dp);
    }
};