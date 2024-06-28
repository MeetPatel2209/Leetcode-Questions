class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> inDegree(n,0);
        for(auto road : roads) {
            inDegree[road[0]]++;
            inDegree[road[1]]++;
        }
        priority_queue<pair<long long,long long>> pq;
        for(int i=0;i<n;i++) {
            pq.push({inDegree[i],i});
        }
        long long count = n;
        long long sum = 0;
        vector<int> imp(n);
        while(!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            sum += temp.first*count;
            count--;
        }
        return sum;
    }
};