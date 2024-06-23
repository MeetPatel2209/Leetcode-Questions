class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int,int>> maxHeap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        int l =0,r = 0;
        int n = nums.size();
        int ans = 0;
        while(r < n) {
            maxHeap.push({nums[r],r});
            minHeap.push({nums[r],r});
            
            while(maxHeap.top().first - minHeap.top().first > limit) {
                l = min(maxHeap.top().second,minHeap.top().second) + 1;
                
                while(maxHeap.top().second < l) maxHeap.pop();
                while(minHeap.top().second < l) minHeap.pop();
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};