class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto flight : flights) {
            int to = flight[0];
            int from = flight[1];
            int price = flight[2];
            adj[to].push_back({from,price});
        }
        vector<int> dist(n,1e9);
        queue<pair<int,int>> pq;
        pq.push({0,src});
        dist[src]=0;
        while(k>=0 && !pq.empty()) {
            int len=pq.size();
            while(len--)
            {   auto it = pq.front();
                int d = it.first;
                int node = it.second;
                pq.pop();
                for(auto adjN : adj[node]) {
                    int an = adjN.first;
                    int dis = adjN.second;
                    if(dist[an]>d+dis) {
                        dist[an] =d + dis;
                        pq.push({d+dis,an});
                    }
                }
            }
            k--;
        }
        if(dist[dst] == 1e9) {
            return -1;
        }
        return dist[dst];
    }
};