class Solution {
  public:
    vector <int> bottomView(Node *root){
        
        map<int,int> map;
        queue<pair<Node* , int>> q;
        q.push({root , 0});
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            int line = p.second;
            map[line] = node->data;
            
            if(node->left != NULL){
                q.push({node->left , line-1});
            }
            if(node->right !=  NULL){
                q.push({node->right , line+1});
            }
        }
        vector<int> btmVeiw;
        for(auto it : map){
            btmVeiw.push_back(it.second);
        }
        return btmVeiw;
    }
};
