#include <iostream>

int main(){
    int size = 5;
    int arr[size];
    std::cout<<"Enter the array elements that needs to be sorted: ";
    for(int i=0; i<size; i++){
        std::cin>>arr[i];
    }
    for(int i=0; i<size; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    std::cout<<"Array elements after applying insertion sort are: ";
    for(int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
    return 0;
}