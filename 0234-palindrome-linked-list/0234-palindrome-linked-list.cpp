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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prevNode = NULL;
        while(slow){
            ListNode* nextNode = slow->next;
            slow->next = prevNode;
            prevNode = slow;
            slow = nextNode;

        }

        ListNode* lft = head;
        ListNode* rght = prevNode;

        while(lft != NULL && rght != NULL){
            if(lft->val != rght->val){
                return false;
            }
            lft = lft->next;
            rght = rght->next;
        }
        return true;
    }
};