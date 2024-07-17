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
    vector<TreeNode*> ans;
    
    void dfs(TreeNode* root,TreeNode* prev,set<int> st) {
        if(root==NULL) return;
        if(root->left == NULL && root->right == NULL) {
            if(st.find(root->val) != st.end()) {
                if(prev == NULL) {
                    root=NULL;
                    return;
                }
                else if(prev != NULL && prev->left == root) {
                    prev->left = NULL;
                }
                else if(prev != NULL && prev->right == root) {
                    prev->right = NULL;
                }
            }
            else {
                if(prev == NULL) ans.push_back(root);
            }
            return;
        }
        if(prev == NULL && st.find(root->val) == st.end()) ans.push_back(root);
        if(st.find(root->val) != st.end()) {
                if(prev != NULL && prev->left == root) {
                        prev->left = NULL;
                    }
                    else if(prev != NULL && prev->right == root) {
                        prev->right = NULL;
                    }
            dfs(root->left,NULL,st);
            dfs(root->right,NULL,st);
        }
        else {
            dfs(root->left,root,st);
            dfs(root->right,root,st);
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> st;
        for(auto x : to_delete) st.insert(x);
        dfs(root,NULL,st);
        return ans;
    }
};