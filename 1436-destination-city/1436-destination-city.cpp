class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> graph;
        for(auto path : paths) {
            graph[path[0]] = path[1];
        }
        string start = paths[0][0];
        string dest;
        while(true) {
            dest = graph[start];
            if(graph.find(dest) == graph.end()) {
                return dest;
            }
            start = dest;
        }
        return "";
    }
};