class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> ump;
        for(auto edge : edges) {
            ump[edge[0]]++;
            ump[edge[1]]++;
        }
        int maxi = INT_MIN;
        int res;
        for(auto p : ump) {
            if(p.second > maxi) {
                maxi = p.second;
                res = p.first;
            }
        }
        return res;
    }
};