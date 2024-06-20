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
    unordered_map<int,int> ump;
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        if(ump.find(k-(root->val)) != ump.end()) return true;
        ump[root->val]++;
        return findTarget(root->left,k) || findTarget(root->right,k);
    }
};