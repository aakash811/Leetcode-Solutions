/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }

    struct ListNode* prevNode = head;
    struct ListNode* currNode = head->next;
    head->next = NULL;

    while(currNode != NULL){
        struct ListNode* next = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = next; 
    }
    return prevNode;
}