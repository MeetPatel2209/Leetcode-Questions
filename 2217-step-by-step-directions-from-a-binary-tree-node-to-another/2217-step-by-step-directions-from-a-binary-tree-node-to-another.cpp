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
    TreeNode* LCA(int node1,int node2,TreeNode* node) {
        if(node == NULL || node->val == node1 || node->val == node2) return node;
        TreeNode* left = LCA(node1,node2,node->left);
        TreeNode* right = LCA(node1,node2,node->right);
        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return node;
    }
    string ansu;
    bool dfs(TreeNode* lca,int start,string &s) {
        if(!lca) return false;
        if(lca->val == start) {
            //ansu = s;
            return true;
        }
        s.push_back('L');
        if(dfs(lca->left,start,s)) {
            return true;
        }
        s.pop_back();
        s.push_back('R');
        if(dfs(lca->right,start,s)) {
            return true;
        }
        s.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* node = root;
        TreeNode* lca = LCA(startValue,destValue,node);
        string s = "";
        dfs(lca,startValue,s);
        string t = "";
        dfs(lca,destValue,t);
        string s1(s.size(),'U');
        // t = t.substr(j);
        cout << s << " " << t;
        return s1 + t;
    }
};