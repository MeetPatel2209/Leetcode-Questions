class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long prevSum = 0;
        long long ans = -1;
        for(int i=0;i<n;i++) {
            if(i>=2 && nums[i] < prevSum) {
                ans = nums[i] + prevSum;
            }
            prevSum+=nums[i];
        }
        return ans;
    }
};