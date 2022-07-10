class Solution {
public:
    // iterative approach using 3 ptr
    ListNode* reverseIterative(ListNode* head){
        // edge case
        if(head == NULL or head->next == NULL){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next;
        
        while(curr != NULL){
            next = curr->next;    
            curr->next = prev;
            prev = curr;
            curr =next;
        }
        return prev;
    }
    
    // recursive approach
    ListNode* reverseRecursive(ListNode* head){
        // base case
        if(head == NULL or head->next == NULL){
            return head;
        }
        ListNode* newHead = reverseRecursive(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    ListNode* reverseList(ListNode* head) {
        // return reverseIterative(head);
        return reverseRecursive(head);
    }
};
