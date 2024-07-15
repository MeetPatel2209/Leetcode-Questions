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
    TreeNode* createTree(int parent,map<int,vector<vector<int>>> &child) {
        if(child.find(parent) == child.end()) {
            TreeNode* node = new TreeNode(parent);
            return node;
        }
        TreeNode* root = new TreeNode(parent);
        for(auto arr : child[parent]) {
            if(arr[1]) {
                root->left = createTree(arr[0],child);
            }
            if(!arr[1]) {
                root->right = createTree(arr[0],child);
            }
        }
        return root;
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,int> ump;
        map<int,vector<vector<int>>> child;
        for(auto desc : descriptions) {
            ump[desc[1]] = desc[0];
            child[desc[0]].push_back({desc[1],desc[2]});
        }
        int parent;
        for(auto p : ump) {
            if(ump.find(p.second) == ump.end()) {
                parent = p.second;
                break;
            }
        }
        return createTree(parent,child);
    }
};