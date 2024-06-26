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
    void inorder(TreeNode* root,vector<int> &arr) {
        if(root==NULL) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    
    TreeNode* createTreeHelper(vector<int> arr,int l,int r) {
        if(l > r) return NULL;
        int root = (l + r)/2;
        TreeNode* node = new TreeNode(arr[root]);
        node->left = createTreeHelper(arr,l,root-1);
        node->right = createTreeHelper(arr,root+1,r);
        
        return node;
    }
    
    TreeNode* createTree(vector<int> arr) {
        int n = arr.size();
        
        return createTreeHelper(arr,0,n-1);
        
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        TreeNode* tree = createTree(arr);
        return tree;
    }
};