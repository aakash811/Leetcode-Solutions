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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL){
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;

        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        temp->next = slow->next;
        return head;
    }
};