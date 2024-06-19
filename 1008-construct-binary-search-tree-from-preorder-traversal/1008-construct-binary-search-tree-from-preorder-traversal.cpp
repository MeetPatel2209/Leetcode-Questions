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
    TreeNode* createtree(vector<int> preorder,int s,int e) {
        if(s > e) return NULL;
        TreeNode* node = new TreeNode(preorder[s]);
        int index;
        for(int i=s;i<=e;i++) {
            if(preorder[i] > node->val) {
                index = i;
                break;
            }
        }
        node->left = createtree(preorder,s+1,index-1);
        node->right = createtree(preorder,index,e);
        return node;
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preIndex = 0;
        int n = preorder.size();
        TreeNode* tree = createtree(preorder,0,n-1);
        return tree;
    }
};