#include <iostream>

struct Node{
    int data;
    Node* next;
};

void insertAtBeginning(Node*& head, int value){
    Node* newNode = new Node;
    newNode->data = value;
    if(head==NULL){
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}
void insertAtEnd(Node*& head, int value){
    Node* newNode = new Node;
    newNode->data = value;
    if(head == NULL){
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}
void deleteFromStart(Node*& head){
    if(head == NULL){
        std::cout<<"Circular Linked List is empty\n";
        return;
    }
    if(head->next==head){
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    Node* last = head;

    while(last->next != head){
        last = last->next;
    }
    head = head->next;
    last->next = head;
    
    delete temp;
}
void deleteFromEnd(Node*& head){
    if(head == NULL){
        std::cout<<"Circular linked list is empty\n";
        return;
    }
    if(head->next==head){
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;

    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = head;
}
void display(Node* head){
    if(head == NULL){
        std::cout<<"Circular linked list is empty\n";
        return;
    }
    Node* temp = head;
    do{
        std::cout<<temp->data<<"->";
        temp = temp->next;
    }while(temp != head);
    std::cout<<"[Head]\n";
}
int main(){
    Node* head = NULL;
    insertAtEnd(head, 6);
    insertAtEnd(head, 12);
    insertAtEnd(head, 18);

    std::cout<<"Circular linked list is: \n";
    display(head);

    insertAtBeginning(head, 3);
    std::cout<<"After inserting at the start: \n";
    display(head);

    deleteFromStart(head);
    std::cout<<"After deleting from the beginning: \n";
    display(head);

    deleteFromEnd(head);
    std::cout<<"After deleting from the end: \n";
    display(head);

    return 0;
}