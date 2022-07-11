class Solution {
public:
    string sum(string s1 , string s2){
        // make sure s2 > s1
        if(s1.size() > s2.size()){
            swap(s1,s2);
        }
        string ans = "";
        
        int n1 = s1.size(); int n2 = s2.size();
        int diff = n2-n1;
        
        int carry = 0;     // initially it was zero
        
        // start from last
        for(int i = n1-1; i >= 0; i--){
            int sum = (s1[i]-'0') + (s2[i+diff]-'0') + carry;
            ans.push_back(sum%10 + '0');
            carry = sum/10;
        }
        // add remaining character of string
        for(int i = n2-n1-1; i >= 0; i--){
            int sum = (s2[i]-'0')+carry;
            
            ans.push_back(sum%10 + '0');
            carry = sum/10;
        }
        
        if(carry){
            ans.push_back(carry + '0');
        }
        return ans;
    }
    // main function
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1 = "";
        string s2 = "";
        
        while(l1 != NULL){
            s1 += (l1->val + '0');
            l1 = l1->next;
        }
        while(l2 != NULL){
            s2 += (l2->val + '0');
            l2 = l2->next;
        }
        
        // reverse both the string to get no.
        reverse(s1.begin() , s1.end());
        reverse(s2.begin() , s2.end());
        
        string ans = sum(s1,s2);   
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        int i = 0;
        while(i < ans.length()){
            ListNode* node = new ListNode(ans[i]-'0');
            
            if(head == NULL){
                head = node;
                tail = node;
            }else{
                tail->next = node;
                tail = tail->next;
            }
            i++;
        }
        return head;
    }
};
