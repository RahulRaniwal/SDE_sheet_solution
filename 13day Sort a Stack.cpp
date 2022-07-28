void sortedInsert(stack<int> &stack , int val){
    // base case
    if(stack.empty()){
        stack.push(val);
        return;
    }
    if(val >= stack.top()){
        stack.push(val);
        return;
    }
    int temp = stack.top();
    stack.pop();
    sortedInsert(stack , val);
    stack.push(temp);
}

void sortStack(stack<int> &stack){
	// base case
    if(stack.empty()){
        return;
    }
    int val = stack.top();
    stack.pop();
    sortStack(stack);
    // insert in sorted way
    sortedInsert(stack , val);
}
