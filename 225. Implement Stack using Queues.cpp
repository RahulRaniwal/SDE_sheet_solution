/****************** using 2 queue **************************/
//             queue<int> q1;
//         queue<int> q2;
//     MyStack() {
       
//     }
    
//     void push(int x) {
//         q2.push(x);
//         // copy q1 into q2
//         while(!q1.empty()){
//             q2.push(q1.front());
//             q1.pop();
//         }
//         swap(q1 , q2);
//     }
    
//     int pop() {
//         int val = q1.front();
//         q1.pop();
//         return val;
//     }
    
//     int top() {
//         return q1.front();
//     }
    
//     bool empty() {
//         return q1.empty();
//     }
/************************************************************/

/*********************** using single queue ****************/
class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        // push and size-1 element form queue
        int i = 1;
        while(i < q.size()){
            q.push(q.front());
            q.pop();
            i++;
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
