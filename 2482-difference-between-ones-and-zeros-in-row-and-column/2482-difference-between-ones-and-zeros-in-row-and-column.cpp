class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<int,pair<int,int>> rowC;
        unordered_map<int,pair<int,int>> colC;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1) {
                    rowC[i].second++;
                    colC[j].second++;
                }
                else if(grid[i][j] == 0) {
                    rowC[i].first++;
                    colC[j].first++;
                }
            }
        }
        for(int i = 0;i<n;i++) {
            for(int j=0;j<m;j++) {
                grid[i][j] = rowC[i].second + colC[j].second - rowC[i].first - colC[j].first;
            }
        }
        return grid;
    }
};