class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        int l=0,r=0;
        int maxi = INT_MIN;
        int n = nums.size();
        while(r<n) {
            ump[nums[r]]++;
            while(l<r && ump[nums[r]]>k){
                ump[nums[l++]]--;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};