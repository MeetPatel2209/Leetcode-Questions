class Solution {
public:
    bool dfs(int src,int n,int destination,vector<int> adj[n],vector<int> &vis) {
        if(src == destination) return true;
        vis[src] = 1;
        for(auto u : adj[src]) {
            if(vis[u] == 0) {
                if(dfs(u,n,destination,adj,vis) == true) return true;
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n,0);
        if(dfs(source,n,destination,adj,vis) == true) return true;
        else return false;
    }
};