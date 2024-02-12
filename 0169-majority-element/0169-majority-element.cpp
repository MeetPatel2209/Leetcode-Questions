class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto x : nums) {
            freq[x]++;
        }
        int maxi = INT_MIN;
        int ans;
        for(auto p : freq) {
            if(maxi < p.second) {
                ans=p.first;
                maxi = p.second;
            }
        }
        return ans;
    }
};