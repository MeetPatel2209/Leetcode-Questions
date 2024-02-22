class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        if(n == 1 && trust.empty()) return 1;
        for(auto t : trust) {
            mp1[t[1]]++;
            mp2[t[0]]++;
        }
        vector<int> vec;
        for(auto p : mp1) {
            if(p.second == n-1) {
                vec.push_back(p.first);
            }
        }
        for(auto x : vec) {
            if(mp2.find(x) != mp2.end()) continue;
            else {
                return x;
            }
        }
        return -1;
    }
};