class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i = 0;i<n;i++) {
            for(auto v : graph[i]) {
                adj[v].push_back(i);
            }
        }
        vector<int> inDegree(n);
        for(int i = 0;i<n;i++) {
            for(auto v : adj[i]) {
                inDegree[v]++;
            }
        }
        queue<int> q;
        for(int i = 0;i<n;i++) {
            if(inDegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(auto it : adj[temp]) {
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};