#include <iostream>

struct Node{
    int data;
    Node* next;
    Node* prev;
};

void insertAtStart(Node*& head, int value){
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

    if(head != NULL){
        head->prev =newNode;
    }
    head = newNode;
}

void insertAtEnd(Node*& head, int value){
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
        return;
    }
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteFromStart(Node*& head){
    if(head == NULL){
        std::cout<<"Doubly linked list is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;

    if(head != NULL){
        head->prev = NULL;
    }
    delete temp;
}

void deleteFromEnd(Node*& head){
    if(head == NULL){
        std::cout<<"Doubly linked list is empty\n";
        return;
    }
    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;

    delete temp;
}

void displayForward(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }

    std::cout << "NULL\n";
}

void displayBackward(Node* head)
{
    if (head == NULL)
        return;

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        std::cout << temp->data << " <-> ";
        temp = temp->prev;
    }

    std::cout << "NULL\n";
}

int main()
{
    Node* head = NULL;

    insertAtEnd(head, 15);
    insertAtEnd(head, 20);
    insertAtEnd(head, 36);

    std::cout << "Forward list:\n";
    displayForward(head);

    std::cout << "Backward list:\n";
    displayBackward(head);

    insertAtStart(head, 5);

    std::cout << "\nAfter inserting at beginning:\n";
    displayForward(head);

    insertAtEnd(head, 40);

    std::cout << "After inserting at end:\n";
    displayForward(head);

    deleteFromStart(head);

    std::cout << "After deleting from beginning:\n";
    displayForward(head);

    deleteFromEnd(head);

    std::cout << "After deleting from end:\n";
    displayForward(head);

    return 0;
}