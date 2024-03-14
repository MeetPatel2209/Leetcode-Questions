class Solution {
public:
    int helper(vector<int>& nums,int goal) {
        int l = 0,r = 0;
        int n = nums.size();
        int sum = 0;
        int cnt = 0;
        while(r<n) {
            sum+=nums[r];
                while(l <= r && sum>goal) {
                    sum-=nums[l];
                    l++;
                }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal) - helper(nums,goal-1);
    }
};