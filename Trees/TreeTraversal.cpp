#include <iostream>

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createTreeNode(int value){
    TreeNode* newNode = new TreeNode();
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

// Preorder Traversal(Root->Left->Right)
void preOrder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    std::cout<<root->value<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
// Inorder Traversal(Left->Root->Right)
void inOrder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    inOrder(root->left);
    std::cout<<root->value<<" ";
    inOrder(root->right);
}
// Postorder Traversal(Left->Right->Root)
void postOrder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    std::cout<<root->value<<" ";
}

int main(){
    TreeNode* root = createTreeNode(10);
    TreeNode* node1 = createTreeNode(12);
    TreeNode* node2 = createTreeNode(5);
    TreeNode* node3 = createTreeNode(20);
    TreeNode* node4 = createTreeNode(25);

    root->left = node1;
    root->right = node2;

    node1->left = node3;
    node1->right = node4;

    std::cout<<"Preorder traversal of a Binary tree: ";
    preOrder(root);

    std::cout<<"\nInoder traversal of a Binary tree: ";
    inOrder(root);

    std::cout<<"\nPostorder traversal of a Binary tree: ";
    postOrder(root);

    return 0;
}