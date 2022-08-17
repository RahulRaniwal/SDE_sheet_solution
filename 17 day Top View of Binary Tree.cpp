class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root){
        
        map<int,int>map;
        queue<pair<Node* , int>> q;
        vector<int> topView;
        q.push({root , 0});
        
        while(!q.empty()){
            auto p = q.front(); q.pop();
            Node* node = p.first;
            int line = p.second;
            
            if(map.find(line) == map.end()){
                map[line] = node->data;
            }
            
            if(node->left != NULL){
                q.push({node->left , line-1});
            }
            if(node->right != NULL){
                q.push({node->right , line+1});
            }
        }
        
        for(auto it : map){
            topView.push_back(it.second);
        }
        return topView;
    }

};
