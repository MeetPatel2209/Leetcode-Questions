class Solution {
public:
    
    bool check(int day,vector<int> bloomDay,int m,int k) {
        int cnt = 0;
        int boq = 0;
        for(int i = 0;i<bloomDay.size();i++) {
            if(bloomDay[i] <= day) {
                cnt++;
                if(cnt == k) {
                    boq++;
                    cnt = 0;
                }
            }
            else {
                cnt = 0;
            }
        }
        return boq >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int maxi = INT_MIN;
        for(auto x : bloomDay) {
            maxi = max(maxi,x);
        }
        int ans = -1;
        int low = 1,high = maxi;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(check(mid,bloomDay,m,k)) {
                high = mid - 1;
                ans = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};