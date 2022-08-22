class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        
        queue<pair<TreeNode*,int>> q;
        q.push({root , 0});
        
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                int level = q.front().second;
                q.pop();
                temp.push_back(node->val);
                
                if(node->left){
                    q.push({node->left , level+1});
                }
                if(node->right){
                    q.push({node->right , level+1});
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
