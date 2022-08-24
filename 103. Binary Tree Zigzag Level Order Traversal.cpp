class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        
        queue<pair<TreeNode* , int>> q;
        q.push({root , 0});
        bool ltr = 1;
        while(!q.empty()){
            int size = q.size();      
            vector<int> temp;
            for(int i = 0; i < size; i++){
                TreeNode* front = q.front().first;
                int level = q.front().second;       q.pop();
                temp.push_back(front->val);
                
                if(front->left){
                    q.push({front->left , level+1});
                }
                if(front->right){
                    q.push({front->right , level+1});
                }
            }
            if(ltr == 0){
                reverse(temp.begin() , temp.end());
                ltr = 1;
            }else{
                ltr = 0;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
