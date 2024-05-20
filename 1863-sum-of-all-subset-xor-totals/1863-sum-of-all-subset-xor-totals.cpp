class Solution {
public:
    int computeSubset(vector<int> &nums,int i,vector<int> temp) {
        if(i == nums.size()) {
            int ans = 0;
            for(auto x : temp) ans = ans ^ x;
            return ans;
        }
        temp.push_back(nums[i]);
        int take = computeSubset(nums,i+1,temp);
        temp.pop_back();
        int notTake = computeSubset(nums,i+1,temp);
        return take + notTake;
    }
    
    int subsetXORSum(vector<int>& nums) {
        int i = 0;
        vector<int> temp;
        int ans = computeSubset(nums,i,temp);
        return ans;
    }
};