// Last updated: 14/08/2026, 15:36:49
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* newHead = deleteDuplicates(head->next);
        if(head->val==newHead->val){
            return newHead;
        }
        else{
            head->next=newHead;
        }
        return head;
    }
};