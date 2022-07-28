class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2 != 0){
            return false;
        }
        
        stack<char> st;
        int i = 0;
        while(i < s.length()){
            if(s[i] =='(' or s[i] == '[' or s[i] == '{'){
                st.push(s[i]);
            }else if(s[i] == ')' and (!st.empty()) and st.top() == '('){
                st.pop();
            }else if(s[i] == ']' and (!st.empty()) and st.top() == '['){
                st.pop();
            }else if(s[i] == '}' and (!st.empty()) and st.top() == '{'){
                st.pop();
            }else{
                st.push(s[i]);
            }
            i++;
        }
        return !st.size();
    }
};
