class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> mp;
        int target = arr.size()/4;
        for(auto x : arr){
            mp[x]++;
            if(mp[x] > target) {
                return x;
            }
        }
        return -1;
    }
};