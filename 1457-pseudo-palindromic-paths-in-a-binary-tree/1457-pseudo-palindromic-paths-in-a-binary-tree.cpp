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
    bool check(vector<int> &freq) {
        int cnt = 0;
        for(auto x : freq) {
            if(x%2 != 0) {
                cnt++;
            }
        }
        if(cnt<=1) {
            return true;
        }
        return false;
    }
    
    int checkFreq(TreeNode* root,vector<int> freq) {
        if(root == NULL) {
            return 0;
        }
        freq[root->val]++;
        if(root->left == NULL && root->right == NULL) {
            return check(freq) ? 1 : 0;
        }
        return checkFreq(root->left,freq) + checkFreq(root->right,freq);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10,0);
        return checkFreq(root,freq);
    }
};