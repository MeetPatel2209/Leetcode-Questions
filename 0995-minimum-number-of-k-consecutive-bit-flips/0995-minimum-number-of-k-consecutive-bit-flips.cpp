class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int validPastFlips = 0;
        vector<bool> flipped(n,false);
        int count = 0;
        for(int i=0;i<n;i++) {
            if(i>=k) {
                if(flipped[i-k]) {
                    validPastFlips--;
                }
            }
            if(validPastFlips%2 == nums[i]) {
                if(i + k > nums.size()) {
                    return -1;
                }
                validPastFlips++;
                flipped[i] = true;
                count++;
            }
        }
        return count;
    }
};