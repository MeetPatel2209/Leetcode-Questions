class DisjointSet {
    public:
    int n;
    vector<int> par;
    vector<int> rank;
    
    DisjointSet(int n) {
        par.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<n+1;i++) {
            par[i] = i;
        }
    }
    
    int find_par(int u) {
        if(u == par[u]) {
            return u;
        }
        else return par[u] = find_par(par[u]);
    }
    
    void unionByRank(int u,int v) {
        int pu = find_par(u);
        int pv = find_par(v);
        if(pu == pv) return;
        if(rank[pu] > rank[pv]) {
            par[pv] = pu;
        }
        else if(rank[pu] < rank[pv]) {
            par[pu] = pv;
        }
        else {
            par[pu] = pv;
            rank[pv]+=1;
        }
    }
    
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = INT_MIN,maxCol = INT_MIN;
        for(auto edge : stones) {
            maxRow = max(maxRow,edge[0]);
            maxCol = max(maxCol,edge[1]);
        }
        DisjointSet d(maxRow+maxCol+1);
        unordered_map<int,int> ump;
        for(auto edge : stones) {
            int row = edge[0];
            int col = edge[1] + maxRow + 1;
            d.unionByRank(row,col);
            ump[row] = 1;
            ump[col] = 1;
        }
        int con = 0;
        for(auto p : ump) {
            if(d.find_par(p.first) == p.first) {
                con++;
            }
        }
        return n - con;
        
    }
};