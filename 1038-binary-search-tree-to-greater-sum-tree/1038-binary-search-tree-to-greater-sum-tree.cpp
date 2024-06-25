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
    
    void compute(TreeNode* root,int &sum) {
        if(root == NULL) return;
        compute(root->right,sum);
        sum += root->val;
        root->val = sum;
        compute(root->left,sum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        TreeNode* node = root;
        int sum = 0;
        compute(root,sum);
        return node;
    }
};