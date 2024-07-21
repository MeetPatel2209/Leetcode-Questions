class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> adj(k+1);
        for(auto row : rowConditions) {
            adj[row[0]].push_back(row[1]);
        }
        vector<int>inDegree(k+1,0);
        inDegree[0] = 1;
        for(int i = 1;i<=k;i++) {
            for(auto x : adj[i]) {
                inDegree[x]++;
            }
        }
        int cnt = 0;
        queue<int> q;
        for(int i=1;i<=k;i++) {
            if(inDegree[i] == 0) q.push(i);
        }
        vector<int> rowOrder;
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            cnt++;
            rowOrder.push_back(temp);
            //i++;
            for(auto x : adj[temp]) {
                inDegree[x]--;
                if(inDegree[x] == 0) q.push(x);
            }
        }
        if(cnt != k) return {};
        adj.clear();
        adj.resize(k+1);
        for(auto col : colConditions) {
            adj[col[0]].push_back(col[1]);
        }
        inDegree.clear();
        inDegree.resize(k+1,0);
        for(int i=1;i<=k;i++) {
            for(auto x : adj[i]) {
                inDegree[x]++;
            }
        }
        for(int i=1;i<=k;i++) {
            if(inDegree[i] == 0) q.push(i);
        }
        cnt=0;
        vector<int> colOrder;
        int i = 0;
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            cnt++;
            colOrder.push_back(temp);
            for(auto x : adj[temp]) {
                inDegree[x]--;
                if(inDegree[x] == 0) q.push(x);
            }
        }
        if(cnt != k) return {};
        vector<vector<int>> mat(k,vector<int>(k,0));
        for(int x=0;x<rowOrder.size();x++) {
            for(int y=0;y<colOrder.size();y++) {
                if(colOrder[y] == rowOrder[x]) {
                    mat[x][y] = rowOrder[x];
                }
            }
        }
        return mat;
    }
};