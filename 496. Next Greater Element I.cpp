class Solution {
public:
    // using stack and map
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> map;
        vector<int> ans(nums1.size() , -1);
        int n = nums2.size();
        st.push(nums2[n-1]);
        int i = n-2;
        while(i >= 0){
            
            while(!st.empty() and nums2[i] >= st.top()){
                st.pop();
            }
            if(!st.empty()){
                map[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
            i--;
        }
        
        // creating ans vector
        for(int i = 0; i < nums1.size(); i++){
            if(map[nums1[i]]){
                ans[i] = map[nums1[i]];
            }
        }
        return ans;
    }
};
