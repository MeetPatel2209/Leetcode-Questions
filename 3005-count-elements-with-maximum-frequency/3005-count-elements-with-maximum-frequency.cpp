class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> ump;
        for(auto x : nums) {
            ump[x]++;
        }
        int maxi = INT_MIN;
        int sum = 0;
        for(auto p : ump) {
            if(p.second > maxi) {
                maxi = p.second;
            }
        }
        for(auto p : ump) {
            if(p.second == maxi) {
                sum += p.second;
            }
        }
        return sum;
    }
};