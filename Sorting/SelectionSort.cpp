#include <iostream>

int main(){
    int size = 5;
    int arr[size];
    std::cout<<"Enter the array of numbers you want to sort: ";
    for(int i=0; i<size; i++){
        std::cin>>arr[i];
    }
    for(int i=0; i<size-1; i++){
        int minIndex = i;
        for(int j=i+1; j<size; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i]= arr[minIndex];
        arr[minIndex] = temp;
    }
    std::cout<<"After selection sort, array is: ";
    for(int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
    return 0;
}