class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int> count;
        for(auto b : bank) {
            int cnt = 0;
            for(auto c : b) {
                if(c == '1') {
                    cnt++;
                }
            }
            if(cnt != 0) 
                count.push_back(cnt);
        }
        int ans = 0;
        for(int i=1;i<count.size();i++) {
            ans+=(count[i-1]*count[i]);
        }
        return ans;
    }
};