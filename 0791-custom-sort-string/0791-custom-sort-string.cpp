class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> ump;
        for(auto c : s) {
            ump[c]++;
        }
        string res;
        for(auto c : order) {
            if(ump.find(c) != ump.end()) {
                while(ump[c]>0) {
                    res.push_back(c);
                    ump[c]--;
                }
            }
        }
        for(auto p : ump) {
            if(p.second > 0) {
                int temp = p.second;
                while(temp>0) {
                    res.push_back(p.first);
                    temp--;
                }
            }
        }
        return res;
    }
};