class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int maxi = INT_MIN;
        for(int i = 1;i<points.size();i++) {
            int diff = points[i][0]-points[i-1][0];
            maxi = max(maxi,diff);
        }
        return maxi;
    }
};