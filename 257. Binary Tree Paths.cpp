class Solution {
public:
    void btPath(TreeNode* root , vector<string>& ans , string s){
        if(root->left == NULL and root->right == NULL){
            ans.push_back(s);
            return;
        }
        
        if(root->left){
            btPath(root->left , ans , s + "->" + to_string(root->left->val));
        }
        if(root->right){
            btPath(root->right , ans , s + "->" + to_string(root->right->val));
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        btPath(root , ans , to_string(root->val));
        return ans;
    }
};
