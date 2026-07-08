#include <iostream>
using namespace std;

int sumEven(int n){

    // If n is 0 or negative
    if(n<=0)
        return 0;
    // if n is even    
    if(n%2==0)
        return n + sumEven(n-2);
    else
    // if n is odd
        return sumEven(n-1);
}

int main()
{
    int n;
    cout <<"Enter the number:";
    cin>>n;

    cout<<"sum of even numbers is:"<<sumEven(n);
    return 0;

}    
    
