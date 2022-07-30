class LRUCache {
public:
    
        // doubly linked list class
   class node{
       public:
       int key;
       int val;
       node* next;
       node* prev;
       node(int key , int val){
           this->key = key;
           this->val = val;
       }
   };
    
    node* head = new node(-1 , -1);
    node* tail = new node(-1 , -1);
    int size;
    unordered_map<int , node*> map;     // key and node
    
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
           // add node
       void addNode(node* newNode){
           
           node* temp = head->next;
           newNode->next = temp;
           newNode->prev = head;
           head->next = newNode;
           temp->prev = newNode;
       }
       
       // delete node
       void deleteNode(node* delNode){
           node* delNext = delNode->next;
           node* delPrev = delNode->prev;
           delPrev->next = delNext;
           delNext->prev = delPrev;
           
       }
    
    int get(int key) {
        // check if it exist in the map or not 
        if(map.find(key) != map.end()){
            node* currNode = map[key];
            int ans = currNode->val;
            map.erase(key);
            deleteNode(currNode);   // delete Node
            addNode(currNode);
            map[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value){
        
        if(map.find(key) != map.end()){
            node* currNode = map[key];
            map.erase(key);
            deleteNode(currNode);
            
        }
        if(size == map.size()){
            node* currNode = tail->prev;
            map.erase(currNode->key);
            deleteNode(currNode);
        }
        
        node* newNode = new node(key , value);
        addNode(newNode);
        map[key] = head->next;
    }
};
