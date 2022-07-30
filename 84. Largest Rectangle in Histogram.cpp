class Solution {
public:
    vector<int> nextSmaller(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        
        st.push(-1);
        
        for(int i = n-1; i >= 0; i--){
            while(st.top() != -1 and heights[st.top()] >= heights[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
        vector<int> prevSmaller(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        
        st.push(-1);
        
        for(int i = 0; i < n; i++){
            while(st.top() != -1 and heights[st.top()] >= heights[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> next(n);
        vector<int> prev(n);
        next = nextSmaller(heights);
        prev = prevSmaller(heights);
        
        int largest = INT_MIN;
        
        for(int i = 0; i < heights.size(); i++){
            int length = heights[i];
            if(next[i] == -1){
                next[i] = n;
            }
            int breadth = next[i]-prev[i]-1;
            
            
            int currArea = length * breadth;
            largest = max(largest , currArea);
        }
        return largest;
    }
};
