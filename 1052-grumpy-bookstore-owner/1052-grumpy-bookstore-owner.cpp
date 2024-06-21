class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        for(int i=0;i<customers.size();i++) {
            if(grumpy[i] == 0) ans += customers[i];
        }
        for(int i=0;i<minutes;i++) {
            if(grumpy[i] == 1) ans += customers[i];
        }
        int maxi = ans;
        int left = 0;
        for(int i=minutes;i<customers.size();i++) {
            if(grumpy[left] == 1) ans-=customers[left];
            if(grumpy[i] == 1) ans += customers[i];
            left++;
            maxi = max(maxi,ans);
        }
        return maxi;
    }
};