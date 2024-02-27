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
    int maxi;
    int compute(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int left = compute(root->left);
        int right = compute(root->right);
        maxi = max(maxi,left+right);
        return 1 + max(left,right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        maxi = INT_MIN;
        int res = compute(root);
        return maxi;
    }
};