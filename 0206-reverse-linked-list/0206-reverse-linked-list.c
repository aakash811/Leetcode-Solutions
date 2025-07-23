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
    prevNode->next = NULL;

    while(currNode != NULL){
        struct ListNode* nxtNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nxtNode;
    }
    return prevNode;
}