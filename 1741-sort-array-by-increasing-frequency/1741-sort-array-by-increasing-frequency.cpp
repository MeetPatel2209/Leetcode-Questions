class Solution {
public:

    static bool comp(pair<int,int> &A,pair<int,int> &B) {
        if(A.first == B.first) return A.second > B.second;
        return A.first < B.first;
    }

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> ump;
        for(auto x : nums) ump[x]++;
        vector<pair<int,int>> arr;
        for(auto p : ump) arr.push_back({p.second,p.first});
        sort(arr.begin(),arr.end(),comp);
        int i = 0;
        for(auto x : arr) {
            int temp = x.first;
            while(temp--) {
                nums[i++] = x.second;
            }
        }
        return nums;
    }
};