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
    void checkLeafNode(TreeNode* root,vector<int> &arr) {
        if(root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            arr.push_back(root->val);
        }
        checkLeafNode(root->left,arr);
        checkLeafNode(root->right,arr);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1;
        vector<int> arr2;
        checkLeafNode(root1,arr1);
        checkLeafNode(root2,arr2);
        if(arr1.size()!=arr2.size()) {
            return false;
        }
        else {
            for(int i=0;i<arr1.size();i++) {
                if(arr1[i] != arr2[i]) {
                    return false;
                }
            }
            return true;
        }
    }
};