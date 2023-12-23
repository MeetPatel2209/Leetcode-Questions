class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> coord;
        int x = 0;
        int y = 0;
        int n = path.size();
        coord.insert({0,0});
        for(auto p : path) {
            if(p == 'N') {
                y = y + 1; 
            }
            else if(p == 'S') {
                y=y-1;
            }
            else if(p == 'W') {
                x = x-1;
            }
            else if(p == 'E'){
                x = x+1;
            }
            if(coord.find({x,y}) != coord.end()) {
                return true;
            }
            coord.insert({x,y});
        }
        return false;
    }
};