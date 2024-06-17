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
    TreeNode* compute(TreeNode* root,TreeNode* p,TreeNode* q) {
        if(root == p || root == q || root == NULL) return root;
        
        TreeNode* left = compute(root->left,p,q);
        TreeNode* right = compute(root->right,p,q);
        
        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return root;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        return compute(root,p,q);
    }
};