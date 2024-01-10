/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void makeGraph(TreeNode* temp,unordered_map<int,unordered_set<int>> &graph) {
        if(temp == NULL) {
            return;
        }
        if(temp->left != NULL) {
            graph[temp->val].insert(temp->left->val);
            graph[temp->left->val].insert(temp->val);
        }
        if(temp->right != NULL) {
            graph[temp->val].insert(temp->right->val);
            graph[temp->right->val].insert(temp->val);
        }
        makeGraph(temp->left,graph);
        makeGraph(temp->right,graph);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,unordered_set<int>> graph;
        TreeNode* temp = root;
        makeGraph(temp,graph);
        queue<int> q;
        q.push(start);
        unordered_set<int> visited;
        visited.insert(start);
        int cnt = 0;
        while(!q.empty()) {
            int n = q.size();
            for(int i=0;i<n;i++) {
                int node = q.front();
                q.pop();
                for(auto v : graph[node]) {
                    if(visited.find(v) == visited.end()) {
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }
            cnt++;
        }
        return cnt-1;
    }
};