#include <iostream>
using namespace std;

int countDigit(int n){
    if (n<0)
        return -n;
    if(n<10)
        return 1;
    else 
        return 1 + countDigit(n/10);
}
int main(){
    int n;
    cout<<"Enter the number:";
    cin>>n;

    cout<<"The total number of digits in this number are: "<<countDigit(n);

    return 0;
}