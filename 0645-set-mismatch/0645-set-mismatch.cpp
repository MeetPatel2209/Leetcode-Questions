class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n+1,0);
        for(auto x : nums) {
            arr[x]++;
        }
        vector<int> res;
        for(int i=1;i<=n;i++) {
            if(arr[i] == 2) {
                res.push_back(i);
            }
        }
        for(int i=1;i<=n;i++) {
            if(arr[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};