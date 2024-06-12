class Solution {
public:
    
    int helper(vector<int> nums,int k) {
        unordered_map<int,int> ump;
        int l = 0,r = 0,n=nums.size();
        int cnt = 0;
        while(r < n) {
            ump[nums[r]]++;
            while(l <= r && ump.size() > k) {
                ump[nums[l]]--;
                if(ump[nums[l]] == 0) ump.erase(nums[l]);
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);
    }
};