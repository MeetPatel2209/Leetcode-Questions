class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minx=INT_MAX,miny=INT_MAX,maxx=-1,maxy=-1;
        int n = grid.size();
        int m =grid[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1) {
                    minx = min(minx,i);
                    miny = min(miny,j);
                    maxx = max(maxx,i);
                    maxy = max(maxy,j);
                }
            }
        }
        return (maxx-minx+1)*(maxy-miny+1);
    }
};