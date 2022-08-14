/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

vector<int> leftView(Node *root){
   vector<int> ans;
   if(root == NULL){
       return ans;
   }
   vector<int> map(101 , 0);
   queue<pair<Node*,int>> q;
   int level = 1;
   q.push({root , level});
   
   while(!q.empty()){
       pair<Node*,int> curr = q.front();
       q.pop();
       int val = curr.first->data;    int lev = curr.second;
       if(map[lev] != 1){
           ans.push_back(val);
           map[lev] = 1;
       }
       if(curr.first->left){
          q.push({curr.first->left , lev+1}); 
       }
       if(curr.first->right){
          q.push({curr.first->right , lev+1}); 
       }
      
   }
   return ans;
}
