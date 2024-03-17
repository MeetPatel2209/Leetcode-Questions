class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> ump;
        ump[0] = -1;
        int maxi = 0, count = 0;
        for(int i=0;i<n;i++) {
            count+= (nums[i] == 1 ? +1 : -1);
            if(ump.find(count) != ump.end()) {
                maxi = max(maxi, i - ump[count]);
            }
            else {
                ump[count]=i;
            }
        }
        return maxi;
        
    }
};