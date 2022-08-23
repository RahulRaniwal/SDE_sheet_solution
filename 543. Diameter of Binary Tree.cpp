class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root , int &dia){
        if(root == NULL){
            return 0;
        }
        int lh = diameterOfBinaryTree(root->left , dia);
        int rh = diameterOfBinaryTree(root->right , dia);
        
        dia = max(dia , lh+rh);
        return 1 + max(lh , rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        diameterOfBinaryTree(root , dia);
        return dia;
    }
};
