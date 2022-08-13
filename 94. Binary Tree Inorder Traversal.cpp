class Solution {
public:
    void inorder(TreeNode* root , vector<int>& in){
        if(root == NULL){
            return;
        }
        inorder(root->left , in);
        in.push_back(root->val);
        inorder(root->right , in);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        inorder(root , in);
        return in;
    }
};
