class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i=0,j=n-1;
        int cnt=0;
        while(i<j) {
            if(k == nums[i]+nums[j]) {
                cnt++;
                i++;
                j--;
            }
            else if(k>nums[i]+nums[j]) {
                i++;
            }
            else{
                j--;
            }
        }
        return cnt;
    }
};