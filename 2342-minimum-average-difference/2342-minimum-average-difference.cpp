class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n+1,0);
        for(int i=0;i<n;i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }
        long long mini = 1e9;
        int ind=-1;
        for(int i=0;i<n;i++) {
            long long left = prefix[i+1]-prefix[0];
            long long right = prefix[n]-prefix[i+1];
            if(n-i-1>0) right = right/(n-i-1);
            else right = 0;
            left = left/(i+1);
            if(mini > abs(left - right)) {
                mini = abs(left-right);
                ind = i;
            }
        }
        return ind;
    }
};