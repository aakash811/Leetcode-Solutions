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
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast == NULL){
            ListNode* tempFast = slow;
            while(tempFast->next != NULL){
                tempFast = tempFast->next;
            } 
            fast = tempFast;
            
            ListNode* tempSlow1 = head;
            while(tempSlow1->next != slow){
                tempSlow1 = tempSlow1->next;
            }
            tempSlow1->next = NULL;
        }

        ListNode* rev = slow->next;
        ListNode* prev = NULL;

        while(slow != NULL){
            slow->next = prev;
            prev = slow;
            slow = rev;
            if(rev != NULL){
                rev = rev->next;
            }
        }

        // while(head != NULL){
        //     cout<<"head-> "<<head->val<<endl;
        //     head = head->next;
        // }
        // while(fast != NULL){
        //     cout<<"fast-> "<<fast->val<<endl;
        //     fast = fast->next;
        // }

        while(head != NULL && fast != NULL){
            if(head->val != fast->val){
                return false;
            }
            else{
                head = head->next;
                fast = fast->next;
            }
        }

        return true;
    }
};