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
    int maxSum = INT_MIN;
    int calcMax(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int leftSum = root->val + calcMax(root->left);
        int rightSum = root->val + calcMax(root->right);
        int localMax = leftSum + rightSum -root->val;
        maxSum = max(maxSum,max(leftSum,max(rightSum,max(localMax,root->val))));
        return  max(root->val,max(leftSum,rightSum));
    }

    int maxPathSum(TreeNode* root) {
        int sum = calcMax(root);
        return maxSum;
    }
};