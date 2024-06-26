class DisjointSet {
    public:
    int n;
    vector<int> par;
    vector<int> rank;
    
    DisjointSet(int n) {
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) {
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet d(n);
        unordered_map<string,int> ump;
        for(int i=0;i<n;i++) {
            for(int j = 1;j<accounts[i].size();j++) {
                if(ump.find(accounts[i][j]) != ump.end()) {
                    d.unionByRank(ump[accounts[i][j]],i);
                }
                else {
                    ump[accounts[i][j]] = i;
                }
            }
        }
        unordered_map<int,vector<int>> mp;
        for(int i = 0;i<n;i++) {
            mp[d.find_par(i)].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto p : mp) {
            vector<string> temp;
            if(p.second.size() == 1) {
                set<string> st(accounts[p.first].begin()+1,accounts[p.first].end());
                temp.push_back(accounts[p.first][0]);
                while(st.empty() != true) {
                    auto it = st.begin();
                    temp.push_back(*it);
                    st.erase(it);
                }
            }
            else {
                set<string> st(accounts[p.first].begin()+1,accounts[p.first].end());
                for(int i=0;i<p.second.size();i++) {
                    for(int j=1;j<accounts[p.second[i]].size();j++) {
                        st.insert(accounts[p.second[i]][j]);
                    }
                }
                temp.push_back(accounts[p.first][0]);
                while(st.empty() != true) {
                    auto it = st.begin();
                    temp.push_back(*it);
                    st.erase(it);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};