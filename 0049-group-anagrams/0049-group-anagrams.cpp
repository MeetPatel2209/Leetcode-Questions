class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ump;
        for(auto str : strs) {
            string temp = str;
            sort(temp.begin(),temp.end());
            ump[temp].push_back(str);
        }
        int i=0;
        vector<vector<string>> res;
        for(auto p : ump) {
            res.push_back(p.second);
        }
        return res;
    }
};