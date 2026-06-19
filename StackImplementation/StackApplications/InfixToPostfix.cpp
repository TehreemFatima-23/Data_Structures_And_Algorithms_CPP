#include <iostream>
using namespace std;

int main() {
    string exp = "A-B^C/D+G";

    // Create array to hold our operators
    char stack[100];
    int top = -1; // -1 means the box is completely empty

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        // If it's a letter (A, B, C), just print it right away
        if (ch >= 'A' && ch <= 'Z') {
            cout << ch;
        }
        // If it's an operator
        else {
            // Find the priority of the current character
            int chPriority = 0;
            if (ch == '+' || ch == '-') chPriority = 1;
            if (ch == '*' || ch == '/') chPriority = 2;
            if (ch == '^') chPriority = 3; 

            // Check if we need to kick out older operators from our box
            while (top != -1) {
                // Find the priority of whatever is currently sitting on top of the box
                char topChar = stack[top];
                int topPriority = 0;
                if (topChar == '+' || topChar == '-') topPriority = 1;
                if (topChar == '*' || topChar == '/') topPriority = 2;
                if (topChar == '^') topPriority = 3; 
                // Special right-to-left rule for ^ (Power doesn't pop power)
                if (topChar == '^' && ch == '^') {
                    break;
                }

                // If the old operator is stronger or equal, print it and remove it
                if (topPriority >= chPriority) {
                    cout << topChar;
                    top = top - 1; // Move the top marker down
                } else {
                    break; // If it's weaker, stop looking
                }
            }

            // Put our current operator into the box
            top = top + 1; // Move the marker up to a fresh slot
            stack[top] = ch;
        }
    }

    // Print anything that is still left over in the box
    while (top != -1) {
        cout << stack[top];
        top = top - 1;
    }

    cout << endl;
    return 0;
}