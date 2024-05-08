class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,int> ump;
        int n = score.size();
        for(int i = 0;i<n;i++) {
            ump[score[i]] = i;
        }
        vector<string> ans(n);
        sort(score.begin(),score.end());
        for(int i=n-1;i>=0;i--) {
            if(i == n-1) {
                ans[ump[score[i]]] = "Gold Medal"; 
            }
            else if(i == n-2) {
                ans[ump[score[i]]] = "Silver Medal";
            }
            else if(i == n-3) {
                ans[ump[score[i]]] = "Bronze Medal";
            }
            else {
                ans[ump[score[i]]] = to_string(n-i);
            }
        }
        return ans;
    }
};