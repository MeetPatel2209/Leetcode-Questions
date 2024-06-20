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
class BSTIterator {
public:
    TreeNode* curr;
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        curr = root;
        while(curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr=root;
    }
    
    int next() {
        auto temp = st.top();
        st.pop();
        int val = temp->val;
        if(temp->right) {
            temp = temp->right;
            while(temp) {
                st.push(temp);
                temp = temp->left;
            }
        }
        return val;
    }
    
    bool hasNext() {
        if(!st.empty()) return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */