/********************* Approach 1 ****************************/
class Solution {
public:
    // reverse LL
    ListNode* reverseLL(ListNode* head){
        // base case
        if(head == NULL or head->next == NULL){
            return head;
        }
        ListNode* newHead = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    
    // breaking linked list into two half
    bool isPalindrome(ListNode* head) {
        
        ListNode* slow = head , *fast = head;  
        while(fast->next != NULL and fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* newHead = slow->next;
        newHead = reverseLL(newHead);
        // breaking ll into two halves
        slow->next = NULL;
        
        ListNode* temp1 = head;
        ListNode* temp2 = newHead;
        while(temp2 !=NULL){
            if(temp1->val != temp2->val){
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        // rejoining of linked list
        newHead = reverseLL(newHead);
        slow->next = newHead;
        
        return true;
    }
};

/******************** Approach 2************************/

class Solution {
public:
    int len(ListNode* head){
        // base case
        if(head == NULL){
            return 0;
        }
        return 1 + len(head->next);
    }
    bool helper(ListNode* right , int count , int n){
        // base case
        if(right == NULL){
            return true;
        }
        
        bool ans = helper(right->next , count+1 , n);
        if(count >= n/2){
            if(ans == false){
                return false;
            }else if(right->val != left->val){
                ans = false;
            }else{
                left = left->next;
                ans = true;
            }
        }
        return ans;
    }
    ListNode* left;
    bool isPalindrome(ListNode* head) {
        left = head;
        int n = len(head);
        return helper(head , 0 , n);
    }
};
