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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp!=0) {
            temp = temp->next;
            cnt++;
        }
        if(cnt == 1 && n == 1) {
            return NULL;
        }
        int pos = cnt - n;
        temp=head;
        if(pos == 0) {
            head = head->next;
            return head;
        }
        pos--;
        while(pos>0 && temp!=NULL) {
            temp = temp->next;
            pos--;
        }
        temp->next = temp->next->next;
        return head;
    }
};