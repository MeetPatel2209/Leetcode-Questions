class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;
        int cnt = n;
        while(l<r) {
            char left = s[l];
            char right = s[r];
            if(left == right) {
            while(l<r && left == s[l]) {
                l++;
                cnt--;
                
            }
            if(l == r) l--;
            while(r>l && right == s[r]) {
                r--;
                cnt--;
            }
            // if(l == r) r++;
            }
            else {
                break;
            }
        }
        return cnt ;
    }
};