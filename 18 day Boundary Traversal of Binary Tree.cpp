#include<stack>

// isleaf fnction
bool isLeaf(TreeNode<int>* root){
    if(root->left == NULL and root->right == NULL){
        return true;
    }
    return false;
}
// add left boundary
void addLeft(TreeNode<int>* root , vector<int>& ans){
    TreeNode<int>* curr = root->left;
    while(curr){
        if(!isLeaf(curr)){
            ans.push_back(curr->data);
        }
        if(curr->left){
            curr = curr->left;
        }else{
            curr = curr->right;
        }
    }
}

// add right boundary
void addRight(TreeNode<int>* root , vector<int>& ans){
    TreeNode<int>* curr = root->right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)){
            temp.push_back(curr->data);
        }
        if(curr->right){
            curr = curr->right;
        }else{
            curr = curr->left;
        }
    }
    for(int i = temp.size()-1; i >= 0; i--){
        ans.push_back(temp[i]);
    }
}

// add leaf nodes
void addLeaf(TreeNode<int>* root , vector<int>& ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left){
        addLeaf(root->left , ans);
    }
    if(root->right){
        addLeaf(root->right , ans);
    }
}
// main function
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    if(!isLeaf(root)){
        ans.push_back(root->data);
    }
  /*  Left -> Leaf -> Right */
    addLeft(root , ans);
    addLeaf(root , ans);
    addRight(root , ans);
    return ans;
}
