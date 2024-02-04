class Solution {
public:
    
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char,int> dictT;
        for(auto c : t) {
            dictT[c]++;
        }
        int req = dictT.size();
        unordered_map<char,int> window;
        int formed=0,l=0,r=0;
        vector<int> ans = {-1,0,0};
        while(r<n) {
            char c = s[r];
            window[c]++;
            if(dictT.find(c) != dictT.end() && window[c] == dictT[c]) {
                formed++;
            }
            while(l<=r && formed == req) {
                c = s[l];
                if(ans[0] == -1 || ans[0] > r-l+1) {
                    ans[0] = r-l+1;
                    ans[1] = l;
                    ans[2] = r;
                }
                window[c]--;
                if(dictT.find(c)!=dictT.end() && dictT[c] > window[c]) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1],ans[0]);
    }
};