class Solution {
public:
    
    int compute(vector<int>& nums, int k) {
        set<int> s;
        int l=0,r=0;
        int ans = 0;
        int n = nums.size();
        unordered_map<int,int> ump;
        while(r<n) {
            ump[nums[r]]++;
            while(ump.size() > k) {
                ump[nums[l]]--;
                if(ump[nums[l]] == 0) ump.erase(nums[l]);
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        // vector<int> res(n+1,0);
        // res[0] = 0;
        // res[1] = 1;
        // unordered_map<int,int> ump;
        // ump[nums[0]]=1;
        // for(int i=2;i<=n;i++) {
        //     if(ump.find(nums[i])==ump.end()) {
        //         res[i]=res[i-1]+1;
        //     }
        //     else {
        //         res[i] = res[i-1];
        //     }
        //     ump[nums[i]]++;
        // }
        return compute(nums,k) - compute(nums,k-1);
    }
};