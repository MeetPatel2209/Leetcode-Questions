class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <=4 ) return 0;
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = n-4;
        int minDiff = INT_MAX;
        while(i < 4) {
            minDiff = min(minDiff,nums[j]-nums[i]);
            i++;
            j++;
        }
        return minDiff;
    }
};