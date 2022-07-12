class Solution {
public:
    // check if cycle is present in a linkedlist and find intersection node
    ListNode* checkFind(ListNode* headA){
        if(headA == NULL or headA->next == NULL){
            return NULL;
        }
        
        ListNode* slow = headA;
        ListNode* fast = headA;
        
        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
        if(slow == fast){
            break;
        }
    }
        // if there is no intersection found
        if(slow != fast){
            return NULL;
        }
        
        slow = headA;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
        
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // edge case
        if(headA == NULL or headB == NULL){
            return NULL;
        }
        
        ListNode* tempA = headA;
        while(tempA->next != NULL){
            tempA = tempA->next;
        }
        //link both ll
        tempA->next = headB;
        
        ListNode* temp1 = headA;
        ListNode* ansNode = checkFind(temp1);
        
        // unlink both ll
        tempA->next = NULL;
        return ansNode;
    }
};
