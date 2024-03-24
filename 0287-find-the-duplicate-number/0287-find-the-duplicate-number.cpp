class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> visited(n,0);
        for(int i=0;i<n;i++) {
            if(visited[nums[i]]) return nums[i];
            visited[nums[i]] = 1;
        }
        return -1;
    }
};