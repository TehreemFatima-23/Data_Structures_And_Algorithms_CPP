#include <iostream> 
using namespace std; 
const int SIZE = 100; 
 
struct Patient
{ 
    string name; 
    int priority; 
}; 
 
struct Ambulance 
{ 
    string id; 
    int arrivalTime; 
}; 
 
// ================= MAX HEAP FOR PATIENTS ================= 
 
class PatientHeap 
{ 
private: 
    Patient heap[SIZE]; 
    int totalPatients; 
 
public: 
    PatientHeap() 
    { 
        totalPatients = 0; 
    } 
    void insertPatient(string name, int priority) 
    { 
        if (totalPatients == SIZE) 
        { 
            cout << "Patient Heap is Full.\n"; 

 
            return; 
        } 
 
        int index = totalPatients; 
 
        heap[index].name = name; 
        heap[index].priority = priority; 
 
        totalPatients++; 
 
        // Heapify Up 
        while (index > 0) 
        { 
            int parent = (index - 1) / 2; 
 
            if (heap[parent].priority < heap[index].priority) 
            { 
                swap(heap[parent], heap[index]); 
                index = parent; 
            } 
            else 
            { 
                break; 
            } 
        } 
 
        cout << "Patient Added Successfully.....\n"; 
    } 
 
    // Treat Highest Priority Patient 
    void treatPatient() 
    { 
        if (totalPatients == 0) 
        { 
            cout << "No Patients Available.\n"; 
            return; 
        } 
 
        cout << "\nTreating Patient: " 
             << heap[0].name 
             << " | Priority: " 
             << heap[0].priority << endl; 
 
        heap[0] = heap[totalPatients - 1]; 
        totalPatients--; 
 
        // Heapify Down 
        int index = 0; 
 
        while (true) 
        { // Formulas
            int left = 2 * index + 1; 
            int right = 2 * index + 2; 
            int largest = index; 
 
            if (left < totalPatients && 
                heap[left].priority > heap[largest].priority) 
            { 

 
                largest = left; 
            } 
 
            if (right < totalPatients && 
                heap[right].priority > heap[largest].priority) 
            { 
                largest = right; 
            } 
 
            if (largest != index) 
            { 
                swap(heap[index], heap[largest]); 
                index = largest; 
            } 
            else 
            { 
                break; 
            } 
        } 
    } 
    void displayPatients() 
    { 
        if (totalPatients == 0) 
        { 
            cout << "No Patients Available.\n"; 
            return; 
        } 
 
        cout << "\n--- Patient Priority Heap ---\n"; 

 
 
        for (int i = 0; i < totalPatients; i++) 
        { 
            cout << heap[i].name 
                 << " | Priority: " 
                 << heap[i].priority << endl; 
        } 
    } 
}; 
 
// ================= MIN HEAP FOR AMBULANCES ================= 
 
class AmbulanceHeap 
{ 
private: 
    Ambulance heap[SIZE]; 
    int totalAmbulances; 
 
public: 
    AmbulanceHeap() 
    { 
        totalAmbulances = 0; 
    } 
    void insertAmbulance(string id, int arrivalTime) 
    { 
        if (totalAmbulances == SIZE) 
        { 
            cout << "Ambulance Heap is Full!\n"; 
            return; 

 
        } 
 
        int index = totalAmbulances; 
 
        heap[index].id = id; 
        heap[index].arrivalTime = arrivalTime; 
 
        totalAmbulances++; 
 
        // Heapify Up 
        while (index > 0) 
        { 
            int parent = (index - 1) / 2; 
 
            if (heap[parent].arrivalTime > heap[index].arrivalTime) 
            { 
                swap(heap[parent], heap[index]); 
                index = parent; 
            } 
            else 
            { 
                break; 
            } 
        } 
 
        cout << "Ambulance Added Successfully....\n"; 
    } 
 
    // Dispatch Fastest Ambulance(The ambulance taking less time will be preferred) 

    void dispatchAmbulance() 
    { 
        if (totalAmbulances == 0) 
        { 
            cout << "No Ambulance Available.\n"; 
            return; 
        } 
 
        cout << "\nDispatching Ambulance: " 
             << heap[0].id 
             << " | Arrival Time: " 
             << heap[0].arrivalTime 
             << " mins" << endl; 
 
        heap[0] = heap[totalAmbulances - 1]; 
        totalAmbulances--; 
 
        // Heapify Down 
        int index = 0; 
 
        while (true) 
        { // Formulas
            int left = 2 * index + 1; 
            int right = 2 * index + 2; 
            int smallest = index; 
 
            if (left < totalAmbulances && 
                heap[left].arrivalTime < heap[smallest].arrivalTime) 
            { 

 
                smallest = left; 
            } 
 
            if (right < totalAmbulances && 
                heap[right].arrivalTime < heap[smallest].arrivalTime) 
            { 
                smallest = right; 
            } 
 
            if (smallest != index) 
            { 
                swap(heap[index], heap[smallest]); 
                index = smallest; 
            } 
            else 
            { 
                break; 
            } 
        } 
    } 
    void displayAmbulances() 
    { 
        if (totalAmbulances == 0) 
        { 
            cout << "No Ambulances Available.\n"; 
            return; 
        } 
 
        cout << "\n--- Ambulance Arrival Heap ---\n"; 

 
 
        for (int i = 0; i < totalAmbulances; i++) 
        { 
            cout << heap[i].id 
                 << " | Arrival Time: " 
                 << heap[i].arrivalTime 
                 << " mins" << endl; 
        } 
    } 
}; 
 
// ================= MAIN FUNCTION ================= 
 
int main() 
{ 
    PatientHeap patientSystem; 
    AmbulanceHeap ambulanceSystem; 
 
    int choice; 
    do 
    { 
        cout << "\n********** CityCare Hospital **********\n"; 
 
        cout << "1. Add Patient\n"; 
        cout << "2. Treat Highest Priority Patient\n"; 
        cout << "3. Display Patients\n"; 
        cout << "4. Add Ambulance\n"; 
        cout << "5. Dispatch Fastest Ambulance\n"; 
        cout << "6. Display Ambulances\n"; 
 
        cout << "0. Exit\n"; 
 
        cout << "Enter Choice: "; 
        cin >> choice; 
 
        switch (choice) 
        { 
        case 1: 
        { 
            string name; 
            int priority; 
 
            cout << "Enter Patient Name: "; 
            cin >> name; 
 
            cout << "Enter Priority: "; 
            cin >> priority; 
 
            if (priority < 0) 
            { 
                cout << "Invalid Priority.\n"; 
            } 
            else 
            { 
                patientSystem.insertPatient(name, priority); 
            } 
 
            break; 
        }

        case 2: 
            patientSystem.treatPatient(); 
            break; 
 
        case 3: 
            patientSystem.displayPatients(); 
            break; 
 
        case 4: 
        { 
            string id; 
            int time; 
 
            cout << "Enter Ambulance ID: "; 
            cin >> id; 
 
            cout << "Enter Arrival Time: "; 
            cin >> time; 
 
            if (time < 0) 
            { 
                cout << "Invalid Time.\n"; 
            } 
            else 
            { 
                ambulanceSystem.insertAmbulance(id, time); 
            } 
 
            break; 
        } 
 
        case 5: 
            ambulanceSystem.dispatchAmbulance(); 
            break; 
 
        case 6: 
            ambulanceSystem.displayAmbulances(); 
            break; 
 
        case 0: 
            cout << "Program Ended.\n"; 
            break; 
 
        default: 
            cout << "Invalid Choice.\n"; 
        } 
 
    } while (choice != 0); 
 
    return 0; 
} 