/************************ ITERATIVE SOLUTION **************************/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       // edge case
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        
        ListNode* newNode = NULL , *tail = NULL;
        if(list1->val <= list2->val){
            newNode = list1;
            tail = list1;
            list1 = list1->next;
        }else{
            newNode = list2;
            tail = list2;
            list2 = list2->next;
        }
        
        while(list1 != NULL and list2 != NULL){
            if(list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
                tail  = tail->next;
            }else{
                tail->next = list2;
                list2 = list2->next;
                tail = tail->next;
            }
        }
        while(list1 != NULL){
            tail->next = list1;
            list1 = list1->next;
            tail = tail->next;
        }
        while(list2!= NULL){
            tail->next = list2;
            list2 = list2->next;
            tail = tail->next;
        }
        return newNode;
    }
};


/************************** RECURSIVE APPROACH ***************************/

    ListNode* mergeTwoListsRecursive(ListNode* list1, ListNode* list2){
        // base case
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        ListNode* newHead;
        if(list1->val <= list2->val){
            newHead = list1;
            newHead->next = mergeTwoListsRecursive(list1->next , list2);
        }else{
            newHead = list2;
            newHead->next = mergeTwoListsRecursive(list1 , list2->next);
        }
        return newHead;
    }

// call this in main function
