class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int cnt = 0;
        sort(happiness.begin(),happiness.end(),greater<int>());
        int n = happiness.size();
        long long sum = 0;
        for(int i=0;i<n;i++) {
            if(cnt == k) break;
            if(happiness[i] - cnt >= 0) {
                sum += happiness[i] - cnt;
                cnt++;
            }
        }
        return sum;
    }
};