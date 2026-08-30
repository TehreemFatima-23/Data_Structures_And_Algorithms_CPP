#include <iostream>

struct Node{
    int data;
    Node* next;
};

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        std::cout<<"["<<temp->data<<"]"<<" Next is ";
        temp = temp->next;
    }
    std::cout<<"[NULL]\n";
}

int main(){
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;

    head->data = 45;
    head->next = second;

    second->data = 50;
    second->next = third;

    third->data = 60;
    third->next = NULL;

    display(head);
    return 0;
}