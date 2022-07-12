// merge 2 ll function
Node* merge(Node* a , Node* b){
    // base case
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    
    Node* temp = new Node(0);
    Node* head = temp;
    
    while(a != NULL and b != NULL){
        if(a->data <= b->data){
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }else{
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    // if one of the linked list is not completed yet so we simply conncet it to the 
    // temp->bottom
    if(a != NULL){
        temp->bottom = a;
    }else{
        temp->bottom = b;
    }
    return head->bottom;
}

Node *flatten(Node *root){
    // base case
    if(root == NULL or root->next == NULL){
        return root;
    }
    
    Node* node = flatten(root->next);
    Node* ans = merge(node , root);
    return ans;
}
