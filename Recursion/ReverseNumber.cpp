#include <iostream>
using namespace std;

void reverseNumber(int n)
{
    if(n == 0)
        return;
    else    
    cout << n % 10;
    reverseNumber(n / 10);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Reversed Number = ";

    reverseNumber(n);

    return 0;
}