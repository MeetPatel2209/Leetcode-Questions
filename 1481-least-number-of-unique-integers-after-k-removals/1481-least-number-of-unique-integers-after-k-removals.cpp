class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto x : arr) {
            mp[x]++;
        }
        vector<int> freq;
        for(auto p : mp) freq.push_back(p.second);
        sort(freq.begin(),freq.end());
        int cnt = 0;
        for(auto x : freq) {
            if(x<=k){ 
                k=k-x;
                cnt++;
            }
        }
        return mp.size()-cnt;
    }
};