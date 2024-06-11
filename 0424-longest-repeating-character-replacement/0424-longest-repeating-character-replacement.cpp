class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> ump;
        int l = 0,r = 0;
        int n = s.size();
        int maxi = INT_MIN;
        int maxf = 0;
        while(r < n) {
            ump[s[r]]++;
            maxf = max(maxf,ump[s[r]]);
            while(l <= r && (r-l+1 - maxf) > k) {
                ump[s[l]]--;
                if(ump[s[l]] == 0) ump.erase(s[l]);
                for(auto p : ump) maxf=max(maxf,p.second);
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};