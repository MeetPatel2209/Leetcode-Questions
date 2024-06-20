class Solution {
public:
    
    void dfs(vector<vector<int>> adj,vector<int> &vis,int node) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(adj,vis,it);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(isConnected[i][j]) {
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> vis(n,0);
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                dfs(adj,vis,i);
                cnt++;
            }
        }
        return cnt;
    }
};