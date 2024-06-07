class Solution {
public:
    
    int check(vector<int> arr,int lim) {
        int n = arr.size();
        int days = 1;
        int curr = 0;
        for(int i=0;i<n;i++) {
            if(curr + arr[i] > lim) {
                days++;
                curr = arr[i];
            }
            else {
                curr+=arr[i];
            }
        }
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0,maxi = INT_MIN;
        for(auto x : weights) {
            sum+=x;
            maxi = max(maxi,x);
        }
        int low = maxi;
        int high = sum;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            int d = check(weights,mid);
            if(d <= days) {
                ans = d;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};