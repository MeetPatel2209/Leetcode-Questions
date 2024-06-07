class Solution {
public:
    
    bool check(vector<int> position,int mid,int m) {
        int n = position.size();
        int cnt = 1;
        int curr = position[0];
        for(int i=1;i<n;i++) {
            if((position[i]-curr) >= mid) {
                cnt++;
                curr = position[i];
            }
            if(cnt >= m) return true;
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int low = 1;
        int high = position[n-1]-position[0];
        int ans = -1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(check(position,mid,m) == true) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};