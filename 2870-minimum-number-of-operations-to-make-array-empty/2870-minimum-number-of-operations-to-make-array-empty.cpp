class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> ump;
        for(auto x : nums){
            ump[x]++;
        }
        int ans=0;
        for(auto p:ump){
            if(p.second == 1) {
                return -1;
            }
            ans += ceil((double)(p.second)/3);
        }
        return ans;
    }
};