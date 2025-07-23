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
    ListNode* merge(ListNode* lft, ListNode* rght){
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(lft && rght){
            if(lft->val < rght->val){
                tail->next = lft;
                lft = lft->next;
            }
            else{
                tail->next=rght;
                rght=rght->next;
            }
            tail = tail->next;
        }

        if(lft){
            tail->next = lft;
        }
        else{
            tail->next = rght;
        }
        
        return dummy.next; 
    }

    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }

        ListNode* mid = getMid(head);
        ListNode* rght = mid->next;
        mid->next = NULL;

        ListNode* lft = sortList(head);
        rght = sortList(rght);

        return merge(lft, rght);
    }
};