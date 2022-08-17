class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        map<int , map<int , multiset<int>>> map;
        queue<pair<TreeNode* , pair<int,int>>> q;
        
        q.push({root , {0 , 0}});
        
        while(!q.empty()){
            auto p = q.front();     q.pop();
            TreeNode* node = p.first;
            int v = p.second.first , h = p.second.second;
            
            map[v][h].insert(node->val);
            
            if(node->left){
                q.push({node->left , {v-1 , h+1}});
            }
            if(node->right){
                q.push({node->right , {v+1 , h+1}});
            }
        }
         
        for(auto p : map){
            vector<int> temp;
            for(auto i : p.second){
                temp.insert(temp.end() , i.second.begin() , i.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
