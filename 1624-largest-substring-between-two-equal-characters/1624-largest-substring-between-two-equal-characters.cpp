class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        vector<int> low26(26,-1);
        vector<int> high26(26,-1);
        for(int i = 0;i<n;i++) {
            char c = s[i];
            if(low26[c-'a'] == -1) {
                low26[c-'a']=i;
            }
            else
                high26[c-'a']=max(high26[c-'a'],i);
        }
        int maxi = INT_MIN;
        for(int i=0;i<26;i++) {
            if(low26[i] != -1 && high26[i]!=-1) {
                maxi=max(maxi,high26[i]-low26[i]-1);
            }
        }
        if(maxi == INT_MIN) {
            return -1;
        }
        return maxi;
    }
};