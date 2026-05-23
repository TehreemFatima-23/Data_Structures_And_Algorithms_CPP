#include <iostream> 
using namespace std; 
 
// Node structure 
struct Node { 
    int id; 
    string name; 
    string status; 
    Node* next; 
}; 
// Head pointer 
Node* head = NULL; 
 
// Function to register participant 
void registerParticipant(int id, string name, string status) { 
    Node* p = new Node(); 
 
    p->id = id; 
    p->name = name; 
    p->status = status; 
    p->next = NULL; 
 
    // Insert at end 
    if (head == NULL) { 
        head = p; 
    } else { 
        Node* temp = head; 
        while (temp->next != NULL) { 
            temp = temp->next; 
        } 
        temp->next = p; 
    } 
    cout << "Participant Registered Successfully!\n"; 
} 
// Function to update status 
void updateStatus(int id, string newStatus) { 
    Node* temp = head; 
 
    while (temp != NULL) { 
        if (temp->id == id) { 
            temp->status = newStatus; 
            cout << "Status Updated Successfully!\n"; 
            return; 
        } 
        temp = temp->next; 
    } 
    cout << "Participant not found!\n"; 
} 
// Function to remove cancelled participants 
void removeCancelled() { 
    Node* temp = head; 
    Node* prev = NULL; 
    int count = 0;  // count deletions 
 
    while (temp != NULL) { 
        if (temp->status == "Cancelled") { 
            count++;  // increment count 
 
            if (temp == head) { 
                head = temp->next; 
                delete temp; 
                temp = head; 
            } else { 
                prev->next = temp->next; 
                delete temp; 
                temp = prev->next; 
            } 
        } else { 
            prev = temp; 
            temp = temp->next; 
        } 
    } 
    if (count > 0) 
        cout << count << " cancelled participants removed!\n"; 
    else 
        cout << "No cancelled participants found.\n"; 
} 
// Function to display confirmed participants 
void displayConfirmed() { 
    Node* temp = head; 
    int count = 0;  // to count confirmed participants 
 
    while (temp != NULL) { 
        if (temp->status == "Confirmed") { 
            // Print heading only once 
            if (count == 0) { 
                cout << "\nConfirmed Participants:\n"; 
            } 
            cout << "ID: " << temp->id << ", Name: " << temp->name << endl; 
            count++; 
        } 
        temp = temp->next; 
    } 
    // If none found 
    if (count == 0) { 
        cout << "No confirmed participants found.\n"; 
    } 
} 
// Main function 
int main() { 
    int choice, id; 
    string name, status; 
    do { 
        cout << "\n***** Event Registration System *****\n"; 
        cout << "1. Register Participant\n"; 
        cout << "2. Update Status\n"; 
        cout << "3. Remove Cancelled Participants\n"; 
        cout << "4. Display Confirmed Participants\n"; 
        cout << "5. Exit\n"; 
        cout << "Enter choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: 
                cout << "Enter ID: "; 
                cin >> id; 
                cout << "Enter Name: "; 
                cin >> name; 
                cout << "Enter Status (Confirmed/Pending/Cancelled): "; 
                cin >> status; 
                registerParticipant(id, name, status); 
                break; 
            case 2: 
                cout << "Enter ID to update: "; 
                cin >> id; 
                cout << "Enter new status: "; 
                cin >> status; 
                updateStatus(id, status); 
                break; 
            case 3: 
                removeCancelled(); 
                break; 
            case 4: 
                displayConfirmed(); 
                break; 
            case 5: 
                cout << "Exiting...\n"; 
                break; 
            default: 
                cout << "Invalid choice!\n"; 
        } 
    } while (choice != 5); 
    return 0; 
} 
