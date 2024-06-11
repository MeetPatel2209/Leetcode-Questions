class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> ump;
        int l = 0,r = 0;
        int n = s.size();
        int maxi = 0;
        while(r<n) {
            ump[s[r]]++;
            while(l < r && ump[s[r]]>1) {
                ump[s[l++]]--;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};