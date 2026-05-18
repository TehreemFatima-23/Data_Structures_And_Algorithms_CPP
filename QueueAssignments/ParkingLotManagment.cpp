#include<iostream> 
using namespace std; 
 
string gates[4] = {"North", "East", "South", "West"}; 
 
int F = -1; 
int R = -1; 
int vehicle =  1; 
int size = 4; 
 
void enqueue(){ 
    int size = 4; 
    if((F == 0 && R == size - 1) || (F == R + 1)){ 
        cout << "Queue Overflow\n"; 
        return; 
    } 
    else if(F == -1 && R == -1){ 
        F = 0; 
        R = 0; 
    } 
    else if(R == size - 1 && F != 0){ 
        R = 0; 
    } 
    else{ 
        R++; 
    } 
    cout << "Vehicle " << vehicle 
         << " entering from " 
         << gates[R] 
         << " Gate\n"; 
    vehicle++; 
} 
 
void resetQueue(){ 
    F = -1; 
    R = -1; 
} 
 
void displayCycle(int c){ 
    cout << "\n----------- Cycle " << c << " -----------\n"; 
} 
 
void simulate(int cycles){ 
    int size = 4; 
    for(int c = 1; c <= cycles; c++){ 
        displayCycle(c); 
        for(int i = 0; i < size; i++){ 
            enqueue(); 
        } 
        resetQueue();   
    } 
} 
int main(){ 
    int cycles; 
    cout << "Enter number of cycles: "; 
    cin  >> cycles; 
    simulate(cycles); 
    cout << "\nParking simulation finished.\n"; 
    return 0; 
}