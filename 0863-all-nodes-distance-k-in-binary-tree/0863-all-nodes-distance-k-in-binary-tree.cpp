/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &ump) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int cnt = q.size();
            for(int i=0;i<cnt;i++) {
                auto temp = q.front();
                q.pop();
                if(temp->left) {
                    ump[temp->left] = temp;
                    q.push(temp->left);
                }
                if(temp->right) {
                    ump[temp->right] = temp;
                    q.push(temp->right);
                }
            }
        }
        return;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> ump;
        markParents(root,ump);
        queue<TreeNode*> q;
        q.push(target);
        int dis = 0;
        unordered_map<TreeNode*,bool> vis;
        vis[target] = true;
        while(q.empty() != true) {
            int cnt = q.size();
            if(dis++ == k) break;
            for(int i=0;i<cnt;i++) {
                auto temp = q.front();
                q.pop();
                vis[temp] = true;
                if(temp->left && !vis[temp->left]) {
                    q.push(temp->left);
                }
                if(temp->right && !vis[temp->right]) {
                    q.push(temp->right);
                }
                if(ump[temp] && !vis[ump[temp]]) {
                    q.push(ump[temp]);
                }
            }
        }
        vector<int> res;
        while(q.empty() != true) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};