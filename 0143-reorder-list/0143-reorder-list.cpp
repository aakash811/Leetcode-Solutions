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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* tempSlow = head;
        while(tempSlow->next != slow){
            tempSlow = tempSlow->next;
        }
        tempSlow->next = NULL;
        if(fast == NULL){
            ListNode* tempFast = slow;
            while(tempFast->next != NULL){
                tempFast = tempFast->next;
            }
            fast = tempFast;
        }

        ListNode* nxt = slow->next;
        ListNode* prev = NULL;

        while(slow != NULL){
            slow->next = prev;
            prev = slow;
            slow = nxt;
            if(nxt != NULL){
                nxt = nxt->next;
            }
        }

        ListNode* pfHead = head;
        ListNode* pfFast = fast;
        while(pfHead != NULL){
            cout<<"pfHead-> "<<pfHead->val<<endl;
            pfHead = pfHead->next;
        }
        while(pfFast != NULL){
            cout<<"pfFast-> "<<pfFast->val<<endl;
            pfFast = pfFast->next;
        }

        struct ListNode* result = new ListNode(); 
        ListNode* res = result;
        int count = 0;
        while(head != NULL && fast != NULL){
            if(count % 2 == 0){
                res->next = head;
                head = head->next;
            }
            else{
                res->next = fast;
                fast = fast->next;
            }
            res = res->next;
            count++;
        }

        if(head != NULL){
            res->next = head;
        }
        else if(fast != NULL){
            res->next = fast;
        }

        head = result->next;
    }
};