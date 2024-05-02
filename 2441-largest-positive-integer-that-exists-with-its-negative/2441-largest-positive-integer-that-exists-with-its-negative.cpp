class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> ump;
        for(auto x : nums) {
            ump[x]++;
        }
        int res = INT_MIN;
        for(auto p : ump) {
            if(ump.find(-p.first)!=ump.end()) {
                res = max(res,abs(p.first));
            }
        }
        if(res == INT_MIN) return -1;
        return res;
    }
};