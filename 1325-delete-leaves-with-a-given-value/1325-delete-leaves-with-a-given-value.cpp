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
    TreeNode* compute(TreeNode* root,int target) {
        if(root == NULL) return NULL;
        if(root->val == target && root->left == NULL && root->right == NULL) return NULL;
        TreeNode* left = compute(root->left,target);
        TreeNode* right = compute(root->right,target);
        TreeNode* node = new TreeNode(root->val,left,right);
        if(node->val == target && node->left == NULL && node->right == NULL) return NULL;
        return node;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return compute(root,target);
    }
};