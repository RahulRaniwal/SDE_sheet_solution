class Solution {
public:
    void deleteNode(ListNode* node) {
        // just update the node value and change its links
        node->val = node->next->val;
        node->next = node->next->next;    
    }
};
