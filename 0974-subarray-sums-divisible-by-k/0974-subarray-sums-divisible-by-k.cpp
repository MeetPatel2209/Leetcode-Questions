class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        int pre = 0;
        int cnt = 0;
        int n = nums.size();
        ump[0] = 1;
        for(int i=0;i<n;i++) {
            pre = (pre + nums[i]%k + k)%k;
            cnt+=ump[pre];
            ump[pre]++;
        }
        return cnt;
    }
};