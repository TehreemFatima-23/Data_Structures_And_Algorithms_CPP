#include <iostream>
using namespace std;

int main() {
    string exp = "83*59+6-";

    int stack[100];
    int top = -1; 

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        // If it's a number ('0' to '9')
        if (ch >= '0' && ch <= '9') {
            // Convert character '2' into actual number 2
            int number = ch - '0'; 
            
            // Push it onto the stack
            top ++;       
            stack[top] = number; // Drop the number in
        }
        // If it's an operator (+, -, *, /)
        else {
            // Pop the second number (top of stack)
            int val2 = stack[top];
            top --; 
            
            // Pop the first number (next one down)
            int val1 = stack[top];
            top --; 

            // Calculate the result based on the operator
            int result = 0;
            if (ch == '+') result = val1 + val2;
            if (ch == '-') result = val1 - val2;
            if (ch == '*') result = val1 * val2;
            if (ch == '/') result = val1 / val2;

            // Push the calculated result back onto the stack
            top ++;
            stack[top] = result;
        }
    }

    // The final answer is the last remaining number on the stack
    cout << "Result = " << stack[top] << endl;

    return 0;
}