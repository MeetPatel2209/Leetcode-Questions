class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto edge : times) {
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(k);
        while(!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            for(auto it : adj[temp]) {
                int dis = it.second;
                int v = it.first;
                if(dist[v] > dist[temp] + dis) {
                    dist[v] = dist[temp] + dis;
                    pq.push(v);
                }
            }
        }
        int maxi = 0;
        for(int i = 1;i<=n;i++) {
            if(dist[i] == INT_MAX) return -1;
            else {
                maxi = max(dist[i],maxi);
            }
        }
        return maxi;
    }
};