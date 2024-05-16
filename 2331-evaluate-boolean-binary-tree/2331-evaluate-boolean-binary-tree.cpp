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
    
    int eval(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) {
            return root->val;
        }
        bool leftSubtree = eval(root->left);
        bool rightSubtree = eval(root->right);
        int op = root->val;
        int temp;
        if(op == 2) {
            temp = leftSubtree || rightSubtree;
        }
        if(op == 3) {
            temp = leftSubtree && rightSubtree;
        }
        return temp;
    }
    
    bool evaluateTree(TreeNode* root) {
        return eval(root);
    }
};