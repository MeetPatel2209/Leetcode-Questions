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
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<TreeNode*>> temp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int cnt = q.size();
            vector<TreeNode*> res;
            for(int i=0;i<cnt;i++) {
                TreeNode* node = q.front();
                q.pop();
                res.push_back(node);
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
            }
            temp.push_back(res);
        }
        return temp[temp.size()-1][0]->val;
    }
};