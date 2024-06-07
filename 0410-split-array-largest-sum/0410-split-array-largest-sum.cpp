class Solution {
public:
    
    int check(vector<int> nums,int mid) {
        int n = nums.size();
        int curr = 0,cnt = 1;
        for(int i=0;i<n;i++) {
            if(curr + nums[i] <= mid) {
                curr+=nums[i];
            }
            else {
                cnt++;
                curr = nums[i];
            }
        }
        return cnt;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        for(auto x : nums) {
            maxi = max(maxi,x);
            sum+=x;
        }
        int low = maxi;
        int ans = -1;
        int high = sum;
        while(low <= high) {
            int mid = low + (high - low)/2;
            int cnt = check(nums,mid);
            if(cnt > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
                ans = mid;
            }
        }
        return low;
    }
};