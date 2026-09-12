#include <iostream>
int main(){
    int size = 5;
    int arr[size];
    std::cout<<"Enter the array of numbers you want to bubble sort: ";
    for(int i=0; i<size; i++){
    std::cin>>arr[i];
    }

    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    std::cout<<"After bubble sort, Array is: ";
    for(int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
    return 0;
}