class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for(auto str : logs) {
            if(str == "../") {
                if(cnt > 0) cnt--;
            }
            else if(str == "./") continue;
            else {
                cnt++;
            }
        }
        return cnt;
    }
};