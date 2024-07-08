class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        map<string,vector<string>> adj;
        map<string,int> inDegree;
        for(int i=0;i<n;i++) {
            for(auto str : ingredients[i]) {
                adj[str].push_back(recipes[i]);
                inDegree[recipes[i]]++;
            }
        }
        queue<string> q;
        vector<string> ans;
        for(auto sup : supplies) q.push(sup);
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            for(auto str : adj[temp]) {
                inDegree[str]--;
                if(inDegree[str] == 0) {
                    q.push(str);
                    ans.push_back(str);
                }
            }
        }
        return ans;
    }
};