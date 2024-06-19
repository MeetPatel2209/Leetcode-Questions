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
     void reverseInorder(TreeNode* node, int& counter, int k, int& kLargest) {
        if (!node || counter >= k) return;
        reverseInorder(node->left, counter, k, kLargest);
        counter++;

        if (counter == k) {
            kLargest = node->val;
            return;
        }
         
        reverseInorder(node->right, counter, k, kLargest);
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int counter = 0;
        reverseInorder(root,counter,k,ans);
        return ans;
    }
};