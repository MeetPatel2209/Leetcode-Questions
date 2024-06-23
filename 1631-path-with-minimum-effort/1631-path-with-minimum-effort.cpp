class Solution {
public:
    int delX[4] = {-1,0,+1,0};
    int delY[4] = {0,-1,0,+1};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        pq.push({0,{0,0}});
        while(!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int d = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;
            if(x == n-1 && y == m-1) return d;
            for(int i=0;i<4;i++) {
                int nx=x+delX[i];
                int ny=y+delY[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m) {
                    int maxe = max(d,abs(heights[nx][ny]-heights[x][y]));
                    if(maxe < dist[nx][ny]) {
                        dist[nx][ny] = maxe;
                        pq.push({maxe,{nx,ny}});
                    }
                }
            }
        }
        return -1;
    }
};