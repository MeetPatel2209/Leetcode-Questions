class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> ump;
        for(auto row : grid) {
            ump[row]++;
        }
        int ans=0;
        for(int i=0;i<grid[0].size();i++) {
            vector<int> temp;
            for(int j=0;j<grid.size();j++) {
                temp.push_back(grid[j][i]);
            }   
            if(ump.find(temp)!=ump.end())
                ans+=ump[temp];
        }
        return ans;
    }
};