#include <iostream>
using namespace std;

int stack[5];
int top = -1;
int score = 0;
int attempts = 0;

void showStack() {
    cout << "\nStack: ";
    if (top == -1) {
        cout << "empty";
    }
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << " | Plates: " << top + 1 << "/5";
    cout << " | Attempts: " << attempts << "/10";
    cout << " | Score: " << score;
    cout << endl;
}

void push() {
    if (attempts >= 10) {
        cout << "No attempts left!" << endl;
        return;
    }
    
    if (top == 4) {
        cout << "Stack full!" << endl;
        return;
    }
    
    int weight;
    cout << "Enter weight: ";
    cin >> weight;
    
    // Check if can add
    if (top != -1 && weight > stack[top]) {
        cout << "Wrong! Heavier on lighter. GAME OVER!" << endl;
        exit(0);
    }
    
    top++;
    stack[top] = weight;
    score = score + 2;
    attempts++;
    cout << "Added!" << endl;
}

void pop() {
    if (top == -1) {
        cout << "Nothing to remove!" << endl;
        return;
    }
    
    cout << "Removed: " << stack[top] << endl;
    top--;
    score = score - 1;
}

void peek() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Top plate: " << stack[top] << endl;
    }
}

int main() {
    int choice;
    
    cout << "***** PLATE GAME *****" << endl;
    cout << "Rule: Don't put heavy on light!" << endl;
    
    while (attempts < 10) {
        showStack();
        
        cout << "\n1. Add" << endl;
        cout << "2. Remove" << endl;
        cout << "3. See top" << endl;
        cout << "4. Quit" << endl;
        cout << "Choose: ";
        cin >> choice;
        
        if (choice == 1) {
            push();
        }
        else if (choice == 2) {
            pop();
        }
        else if (choice == 3) {
            peek();
        }
        else if (choice == 4) {
            cout << "You Quit" << endl;
            break;
        }
        else {
            cout << "Pick only 1-4" << endl;
        }
        
        // Check win
        if (top == 4) {
            showStack();
            cout << "\nCongrats....You WIN" << endl;
            break;
        }
    }
    
    // Check game over
    if (attempts >= 10 && top != 4) {
        cout << "\nGAME OVER....10 attempts used" << endl;
    }
    
    cout << "\nFINAL SCORE: " << score << endl;
    cout << "Plates left: " << top + 1 << endl;
    
    return 0;
}