class Solution {
public:
    
    int lowerBound(int limit,vector<pair<int,int>> arr) {
        int low = 0;
        int high = arr.size()-1;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(limit <= arr[mid].first) {
                low = mid + 1;
                ans = mid;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
    
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> diff;
        unordered_map<int,int> ump;
        for(int i=0;i<difficulty.size();i++) {
            diff.push_back({difficulty[i],profit[i]});
        }
        sort(diff.begin(),diff.end());
        sort(worker.begin(),worker.end());
        int maxi = 0;
        long long int res = 0;
        int index = 0,j = 0;
        while(j != worker.size() && index != profit.size()) {
            if(diff[index].first <= worker[j]) {
                maxi = max(diff[index].second,maxi);
                index++;
            } 
            else {
                res += maxi;
                j++;
            }
        }
        int n = profit.size()-1;
        if(index == profit.size()) {
            while(j != worker.size() && diff[n].first <= worker[j]) {
                res = res + maxi;
                j++;
            }
        }
        return res;
    }
};