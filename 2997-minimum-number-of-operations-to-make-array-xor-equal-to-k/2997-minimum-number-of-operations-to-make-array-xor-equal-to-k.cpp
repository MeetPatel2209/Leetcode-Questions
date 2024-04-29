class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int finalXor = 0;
        for(auto x : nums) {
            finalXor = finalXor ^ x;
        }
        int count = 0;
        
        while(k || finalXor) {
            if((k % 2) != (finalXor % 2)) count++;
            
            k=k/2;
            finalXor=finalXor/2;
        }
        return count;
    }
};