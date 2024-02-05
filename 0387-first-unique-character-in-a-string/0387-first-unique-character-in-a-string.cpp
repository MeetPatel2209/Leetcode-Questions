class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26,0);
        for(auto c : s) {
            count[c-'a']++;
        }
        int ans = -1;
        for(int i=0;i<s.size();i++) {
            int x = count[s[i]-'a'];
            if(x==1) {
                return i;
                
            }
        }
        return -1;
    }
};