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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> arr;
        queue<TreeNode*> q;
        if(root == NULL) return {};
        q.push(root);
        bool dir = false;
        while(!q.empty()) {
            int cnt = q.size();
            vector<int> vec;
            for(int i=0;i<cnt;i++) {
                auto temp = q.front();
                q.pop();
                if(temp != NULL)
                vec.push_back(temp->val);
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right!= NULL) q.push(temp->right);
            }
            if(dir) {
                reverse(vec.begin(),vec.end());
                arr.push_back(vec);
            }
            else {
                arr.push_back(vec);
            }
            dir = !dir;
        }
        return arr;
    }
};