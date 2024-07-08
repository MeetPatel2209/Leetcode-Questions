class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> nums;
        int curr = 0;
        int last;
        for(int i = 1;i<=n;i++) nums.push_back(i);
        while(nums.size() > 1) {
            last = (curr + k - 1)%nums.size();
            //vis[last%n] = 1;
            nums.erase(nums.begin()+last);
            curr = last;
        }
        return nums.front();
    }
};