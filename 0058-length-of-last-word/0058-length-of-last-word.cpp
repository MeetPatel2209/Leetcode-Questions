class Solution {
public:
    int lengthOfLastWord(string s) {
        int space = -1;
        int n = s.size();
        for(int i=0;i<n-1;i++) {
            if(s[i] == ' ' && s[i+1] != ' ') space = i;
        }
        if(space == -1){
            int i = 0;
            while(i<n && s[i] != ' ') {
                i++;
            }
            return i;
        }
        space++;
        int cnt = 0;
        while(space < n && s[space]!=' ') {
            cnt++;
            space++;
        }
        return cnt;
    }
};