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

TreeNode* insert(TreeNode* root, int value){
    if(root == nullptr){
        return createTreeNode(value);
    }
    if(value<root->value){
        root->left = insert(root->left, value);
    }
    else{
        root->right = insert(root->right, value);
    }
    return root;       
}
// Inorder traversal(Left->Root->Right)
void inorder(TreeNode* root)
{
    if(root == nullptr)
        return;

    inorder(root->left);

    std::cout << root->value << " ";

    inorder(root->right);
}
//Search for a value in BSt using this function
bool search(TreeNode* root, int value){
    if(root == nullptr){
        return false;
    }
    if(root->value == value){
        return true;
    }
    if(value < root->value){
        return search(root->left, value);
    }
    return search(root->right, value);
}

TreeNode* deleteNode(TreeNode* root, int value)
{
    if(root == nullptr)
        return root;

    if(value < root->value)
    {
        root->left = deleteNode(root->left, value);
    }
    else if(value > root->value)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if(root->left == nullptr)
        {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        if(root->right == nullptr)
        {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        //With Two children
        TreeNode* temp = root->right;

        while(temp->left != nullptr)
        {
            temp = temp->left;
        }

        root->value = temp->value;

        root->right = deleteNode(root->right, temp->value);
    }

    return root;
}

int main(){
    TreeNode* root = nullptr;

    root = insert(root, 75);
    root = insert(root, 86);
    root = insert(root, 67);
    root = insert(root, 23);
    root = insert(root, 40);
    root = insert(root, 35);
    root = insert(root, 60);

    std::cout<<"\nInorder traversal of a BST: ";
    inorder(root);

    std::cout<<"\nSearching for 67...";
    if(search(root, 67)){
        std::cout<<"Value found\n";
    }
    else{
        std::cout<<"Value not found\n";
    }

    root = deleteNode(root, 35);

    std::cout<<"After deleting 35 BST is: ";
    inorder(root);
    return 0;
}