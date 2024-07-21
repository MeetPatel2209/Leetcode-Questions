class Solution {
public:
    int maxOperations(string s) {
        int i = 0;
        int cnt1 = 0;
        int ans = 0;
        while(i < s.size()) {
            if(s[i] == '1') {
                cnt1++;
                i++;
            }
            else {
                if(cnt1 > 0) {
                    int index = i;
                    while(index < s.size() && s[index] == '0') {
                        index++;
                    }
                    ans+=cnt1;
                    i = index;
                }
                else i++;
            }
        }
        return ans;
    }
};