/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> ump;
        for(auto x : nums) {
            ump[x]++;
        }
        ListNode* node = new ListNode(-1);
        node->next = head;
        ListNode* curr = node;
        ListNode* root = node->next;
        //if(root->next == NULL && ump.find(root->val) == ump.end()) return root;
        //else if(root->next == NULL && ump.find(root->val) != ump.end()) return NULL;
        //root=root->next;
        while(root!=NULL) {
            if(ump.find(root->val) != ump.end()) {
                curr->next = root->next;
                root = root->next;
            }
            else {
                curr = root;
                root=root->next;
            }
        }
        return node->next;
    }
};