class Solution {
public:
    int compute(vector<int> arr,int K) {
        int n = arr.size();
        int l = 0,r = 0;
        int temp = 0;
        int maxi = 0;
        while(r < n) {
            temp += arr[r];
            while(l <= r && temp > K) {
                temp -= arr[l++];
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }


    int equalSubstring(string s, string t, int maxCost) {
        vector<int> arr;
        int n = s.size();
        for(int i=0;i<n;i++) {
            arr.push_back(abs(s[i]-t[i]));
        }
        return compute(arr,maxCost);
    }
};