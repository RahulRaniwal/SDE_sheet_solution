class Solution {
public:
    // length fucntion
    int len(ListNode* head){
        if(head == NULL){
            return 0;
        }
        return 1 + len(head->next);
    }
    // function which perform only one rotation
    ListNode* oneRotation(ListNode* head){
        if(head == NULL or head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;  // breaking link between last node and remaining linked list
        newHead->next = head;   //connect from last node
        return newHead;
    }
    // main function
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL or head->next == NULL){
            return head;
        }
        ListNode* ansNode = head;
        int length = len(head);
        k = k%length;
        while(k--){
             ansNode = oneRotation(ansNode);
        }
        return ansNode;
    }
};
