#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    int stack[100];
    int top = -1;

    while (n > 0) {
        top++;
        stack[top] = n % 2; // remainder
        n = n / 2;
    }

    cout << "Binary: ";
    while (top != -1) {
        cout << stack[top];
        top--;
    }

    return 0;
}