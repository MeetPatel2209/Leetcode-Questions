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
    string res="";
    void dfs(TreeNode* root,string s) {
        if(root == NULL) {
            return;
        }
        s = (char)(root->val + 'a') + s;
        if(root->left == NULL && root->right == NULL) {
            if(res == "" || res > s) res = s;
        }
        
        if(root->left) dfs(root->left,s);
        if(root->right) dfs(root->right,s);
    }
    string smallestFromLeaf(TreeNode* root) {
        string s = "";
        dfs(root,s);
        return res;
    }
};