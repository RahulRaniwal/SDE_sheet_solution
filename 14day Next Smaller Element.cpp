vector<int> nextSmallerElement(vector<int> &arr, int n){
    unordered_map<int,int> map;
    vector<int> ans(n,-1);
    stack<int> st;
    st.push(arr[n-1]);
    
    for(int i = n-2; i >= 0; i--){
        while(!st.empty() and st.top() >= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            map[arr[i]] = st.top();
        }
        if(map.find(arr[i]) != map.end()){
            ans[i] = map[arr[i]];
        }
        st.push(arr[i]);
    }
//     // creating ans vector
//     for(int i = 0; i < n; i++){
//         if(map.find() != map.end()){
//             ans[i] = map[arr[i]];
//         }
//     }
    return ans;
}
