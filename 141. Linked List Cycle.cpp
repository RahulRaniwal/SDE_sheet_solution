class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL or head->next == NULL){
            return false;
        }
        ListNode *slow = head , *fast = head;
        
        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }
        if(slow != fast){
            return false;
        }
        return true;
    }
};
