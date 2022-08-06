// class StockSpanner {
// public:
//     StockSpanner() {
        
//     }
    
//     stack<int> st1;
//     stack<int> st2;
//     int next(int price) {
//         int count = 0;
//         while(!st1.empty() and st1.top() <= price){
//             st2.push(st1.top());
//             count++;
//             st1.pop();
//         }
//         while(!st2.empty()){
//             st1.push(st2.top());
//             st2.pop();
//         }
//         st1.push(price);
//         return count+1;
        
//     }
// };

/****************** above solution gives tle ********************************/

class StockSpanner {
    private:
    stack<pair<int,int>> st;
    public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int days = 1;
        
        while(!st.empty() and st.top().first <= price){
            days += st.top().second;
            st.pop();
        }
        st.push(make_pair(price , days));
        return days;
    }
};
