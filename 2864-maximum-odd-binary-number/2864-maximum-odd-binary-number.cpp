class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = 0;
        int n = s.size();
        for(auto c : s) {
            if(c == '1') cnt++;
        }
        for(int i=0;i<cnt-1;i++) {
            s[i] = '1';
        }
        for(int i=cnt-1;i<n-1;i++) {
            s[i] = '0';
        }
        s[n-1] = '1';
        return s;
    }
};