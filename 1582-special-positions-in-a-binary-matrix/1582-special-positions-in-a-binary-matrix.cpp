class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int,int> rowC;
        unordered_map<int,int> colC;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j] == 1) {
                    rowC[i]++;
                    colC[j]++;
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j] == 1 && rowC[i] == 1 && colC[j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};