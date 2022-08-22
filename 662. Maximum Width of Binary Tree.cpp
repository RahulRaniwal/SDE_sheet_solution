class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        int maxWidth = 0;
        
        queue<pair<TreeNode*,long>> q;
        q.push({root , 0});
        
        while(!q.empty()){
            int size = q.size();
            long mini = q.front().second*1l;
            
            int fi , li;
            for(int i = 0; i < size; i++){
                long currIdx = q.front().second - mini;
                TreeNode* node = q.front().first;
                q.pop();
                
                if(i == 0){
                    fi = currIdx;
                }
                if(i == size-1){
                    li = currIdx;
                }
                
                if(node->left){
                    q.push({node->left , currIdx*2+1});
                }
                if(node->right){
                    q.push({node->right , currIdx*2+2});
                }
            }
            
            maxWidth = max(maxWidth , li-fi+1);
        }
        return maxWidth;
    }
};
