// inorder/preorder traversal with T=O(N) and S=O(1)
// uses the concept of threaded binary tree
// this example is of inorder
#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode *left,*right;
    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
vector<int> getInorder(TreeNode *root){
    vector<int> inorder;
    TreeNode *curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            inorder.push_back(curr->val);
            curr=curr->right;
        }else{
            TreeNode *prev=curr->left;
            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }else{
                prev->right=NULL;
                inorder.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    return inorder;
}
int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->left->right->right=new TreeNode(6);
    root->right=new TreeNode(3);
    vector<int> ans=getInorder(root);
    for(auto &it:ans){
        cout<<it<<" ";
    }
}