class Solution {
public:
    
    bool check(vector<int> &taken) {
        for(auto x : taken) {
            if(x == 0) {
                return true;
            }
        }
        return false;
    }
    
    
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> taken(n,0);
        vector<vector<int>> ans;
        while(check(taken)) {
            set<int> s;
            vector<int> temp;
            for(int i=0;i<n;i++) {
                if(taken[i] == 0 && s.find(nums[i]) == s.end()) {
                    taken[i] = 1;
                    s.insert(nums[i]);
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};