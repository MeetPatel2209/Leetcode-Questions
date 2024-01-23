class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0;
        int i=0;
        while(i<chars.size()) {
            int cnt = 1;
            while(i+cnt < chars.size() && chars[i+cnt] == chars[i]) {
                cnt++;
            }
            chars[res++] = chars[i];
            if(cnt>1) {
                for(char c : to_string(cnt)) {
                    chars[res++] = c;
                }
            }
            i+=cnt;
        }
        return res;
    }
};