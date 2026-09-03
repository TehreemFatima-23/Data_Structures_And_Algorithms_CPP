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

int main(){
    TreeNode* root = createTreeNode(50);
    TreeNode* node1 = createTreeNode(15);
    TreeNode* node2 = createTreeNode(20);
    TreeNode* node3 = createTreeNode(30);
    TreeNode* node4 = createTreeNode(35);

    root->left = node1;
    root->right = node2;

    node1->left = node3;
    node1->right = node4;

    std::cout << "Root: " << root->value << std::endl;

    std::cout << "Root's left: "
              << root->left->value << std::endl;

    std::cout << "Root's right: "
              << root->right->value << std::endl;

    std::cout << "Node1's left: "
              << node1->left->value << std::endl;

    std::cout << "Node2's right: "
              << node1->right->value << std::endl;

    return 0;
}