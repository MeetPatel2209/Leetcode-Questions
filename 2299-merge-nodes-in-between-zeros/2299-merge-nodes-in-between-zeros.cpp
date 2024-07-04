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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head;
        ListNode* zero = head;
        ListNode* root = head;
        curr = curr->next;
        int sum = 0;
        while(curr!=NULL) {
            if(curr->val != 0) {sum += curr->val;curr=curr->next;}
            else {
                zero->val = sum;
                if(curr->next != NULL) 
                    zero->next = curr;
                else {zero->next = NULL;break;}
                zero = curr;
                sum = 0;
                curr=curr->next;
            }
        }
        return root;
    }
};