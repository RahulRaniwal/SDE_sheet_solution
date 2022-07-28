/*************** using 2 stack ****************/
class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> s1; stack<int> s2;
    void push(int x) {
        // push all elements of s1 into s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        //push lement into s1
        s1.push(x);
        // again push all the element into s1 from s2
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int val = s1.top();
        s1.pop();
        return val;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/*************** using 2 stack and O(1) TC of push ****************/
class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> s1; stack<int> s2;
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
           if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() and s2.empty();
    }
};
