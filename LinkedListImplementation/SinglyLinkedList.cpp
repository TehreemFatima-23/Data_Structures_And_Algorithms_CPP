#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// Insert at beginning
void insertBeginning(Node*& head, int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}

// Insert at end
void insertEnd(Node*& head, int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Delete from beginning
void deleteBeginning(Node*& head)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    head = head->next;

    delete temp;
}

// Delete from end
void deleteEnd(Node*& head)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;

    temp->next = NULL;
}

// Display
void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main()
{
    Node* head = NULL;

    insertBeginning(head, 30);
    insertBeginning(head, 20);
    insertBeginning(head, 10);

    cout << "After inserting at beginning:\n";
    display(head);

    insertEnd(head, 40);
    insertEnd(head, 50);

    cout << "After inserting at end:\n";
    display(head);

    deleteBeginning(head);

    cout << "After deleting from beginning:\n";
    display(head);

    deleteEnd(head);

    cout << "After deleting from end:\n";
    display(head);

    return 0;
}