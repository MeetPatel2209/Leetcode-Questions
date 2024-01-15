class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matche) {
        unordered_map<int,int> winners;
        unordered_map<int,int> losers;
        unordered_map<int,int> players;
        unordered_map<int,int> matches;
        for(auto match : matche) {
            int win = match[0];
            int lose = match[1];
            matches[win]++;
            matches[lose]++;
            losers[lose]++;
            winners[win]++;
            players[win]=1;
            players[lose]=1;
        }
        vector<int> res;
        for(auto winner : winners) {
            if(winner.second == matches[winner.first]) {
                res.push_back(winner.first);
            }
        }
        vector<int> res2;
        for(auto loser : losers) {
            if(loser.second == 1) {
                res2.push_back(loser.first);
            }
        }
        vector<vector<int>> ans;
        sort(res.begin(),res.end());
        sort(res2.begin(),res2.end());
        ans.push_back(res);
        ans.push_back(res2);
        return ans;
    }
};