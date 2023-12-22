class Solution {
public:
    
    int countZero(string s1) {
        int cnt=0;
        for(int i=0;i<s1.size();i++) {
            if(s1[i] == '0') {
                cnt++;
            }
        }
        return cnt;
    }
    int countOne(string s1) {
        int cnt=0;
        for(int i=0;i<s1.size();i++) {
            if(s1[i] == '1') {
                cnt++;
            }
        }
        return cnt;
    }
    
    int maxScore(string s) {
        int n = s.size();
        int maxi = INT_MIN;
        for(int i=1;i<n;i++) {
            string s1 = s.substr(0,i);
            string s2 = s.substr(i);
            maxi = max(maxi,countZero(s1)+countOne(s2));
        }
        return maxi;
    }
};