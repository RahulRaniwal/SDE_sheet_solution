/***************** BRUTE FORCE **********************/
class Solution {
public:
    // BRUTE FORCE 
    
    // len of LL
    int len(ListNode* head){
        if(head == NULL){
            return 0;
        }
        return 1 + len(head->next);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int length = len(temp);
        // edge case
        if(length == 1){
            return NULL;
        }
        if(length == n){
            return head->next;
        }
        int i = 1;
        temp = head;
        while(i < length-n){
            temp = temp->next;
            i++;
        }
        ListNode* temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        return head;
    }
};

/************************ O(N) Soluttion one-pass ********************************/

class Solution {
public:
    // O(n)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newHead = new ListNode();
        newHead->next = head;
        ListNode* slow = newHead;
        ListNode* fast = newHead;
        
        int i = 1;
        while(i <= n){
            fast = fast->next;
            i++;
        }
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return newHead->next;
        
  
