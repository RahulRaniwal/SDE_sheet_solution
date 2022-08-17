
void inorder(BinaryTreeNode<int> *root , vector<int>& in){
    if(root == NULL){
        return;
    }
    inorder(root->left , in);
    in.push_back(root->data);
    inorder(root->right , in);
}

void preorder(BinaryTreeNode<int> *root , vector<int>& pre){
    if(root == NULL){
        return;
    }
    pre.push_back(root->data);
    preorder(root->left , pre);
    preorder(root->right , pre);
}

void postorder(BinaryTreeNode<int> *root , vector<int>& post){
    if(root == NULL){
        return;
    }
    postorder(root->left , post);
    postorder(root->right , post);
    post.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
   vector<int> in , pre , post;
    inorder(root , in);
    preorder(root , pre);
    postorder(root , post);
    vector<vector<int>> ans;
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}
