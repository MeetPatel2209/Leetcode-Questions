class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(auto x : arr1) {
            while(x!=0) {
                mp[x]++;
                x/=10;
            }
        }
        int maxi = 0;
        for(auto x : arr2) {
            while(x!=0){
                if(mp.find(x)!=mp.end()) {
                    string temp = to_string(x);
                    maxi = max(maxi,(int)temp.size());
                }
                x/=10;
            }
        }
        return maxi;
        
    }
};