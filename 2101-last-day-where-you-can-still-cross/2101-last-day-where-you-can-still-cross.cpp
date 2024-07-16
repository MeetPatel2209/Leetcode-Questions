class Solution {
public:

bool isPossible(vector<vector<int>>&cells,int row,int col,int mid){
    vector<vector<bool>>vis(row,vector<bool>(col,0));
    for(int i=0;i<mid;i++){
        vis[cells[i][0]-1][cells[i][1]-1]=1;
    }

    queue<pair<int,int>>q;
    for(int c=0;c<col;c++){
        if(vis[0][c]==0){
            q.push({0,c});
            vis[0][c]=1;
        }
    }

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,1,-1};
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int r = it.first;
        int c = it.second;
        if(r==row-1) return true;
        for(int i=0;i<4;i++){
            int nrow = r+dx[i];
            int ncol = c+dy[i];
            if(nrow<0 or ncol<0 or nrow==row or ncol==col or vis[nrow][ncol]==1) continue;
            vis[nrow][ncol]=1;
            q.push({nrow,ncol});
        }
    }
    return false;
}
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();
        int low=1;
        int high=n-1;
        int ans=0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isPossible(cells,row,col,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};