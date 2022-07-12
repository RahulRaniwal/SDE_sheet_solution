class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL or head->next == NULL){
            return NULL;
        }   
        ListNode* slow = head , *fast = head;
        
        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }    
        if(slow != fast){
            return NULL;
        }
        
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
