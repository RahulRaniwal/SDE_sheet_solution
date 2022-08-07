
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n){
        
        stack<int> st;
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        
        while(st.size() >= 2){
            int val1 = st.top();    st.pop();
            int val2 = st.top();    st.pop();
            
            if(M[val1][val2] == 1){
                st.push(val2);
            }else{
                st.push(val1);
            }
        }
        
        int celeb = st.top();
        for(int i = 0; i < n; i++){
            if(i != celeb){
                if(M[celeb][i] == 1 or M[i][celeb] == 0){
                    return -1;
                }
            }
        }
        return celeb;
    }
};
