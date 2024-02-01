class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=2;i<n;i+=3) {
            if(nums[i]-nums[i-2] > k) {
                return res;
            }
        }
        for(int i=0;i<n;i+=3) {
            vector<int> temp;
            for(int j=i;j<=i+2;j++) {
                temp.push_back(nums[j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};