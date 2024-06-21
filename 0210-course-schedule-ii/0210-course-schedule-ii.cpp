class Solution {
public:
    vector<int> canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int> inDegree(numCourses,0);
        for(int i=0;i<numCourses;i++) {
            for(auto j : adj[i]) {
                inDegree[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++) {
            if(inDegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        int cnt = 0;
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            ans.push_back(temp);
            cnt++;
            for(auto it : adj[temp]) {
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        if(cnt != numCourses) return {};
        return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        return canFinish(numCourses,prerequisites);
    }
};