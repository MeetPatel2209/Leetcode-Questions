class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto word : wordDict) {
            dict.insert(word);
        }
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.size();i++) {
            for(int j=i-1;j>=0;j--) {
                if(dp[j]) {
                    string temp = s.substr(j,i-j);
                    if(dict.find(temp) != dict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};