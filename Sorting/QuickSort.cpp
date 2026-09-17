#include <iostream>

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low; j<high; j++){
        if(arr[j]<pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}
void quickSort(int arr[], int low, int high){
    if(low<high){
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex-1);
        quickSort(arr, pivotIndex+1, high);
    }
}
int main(){
    int size = 5; 
    int arr[size];
    std::cout<<"Enter the 5 elements to sort them using Quick Sort: ";
    for(int i=0; i<size; i++){
        std::cin>>arr[i];
    }
    quickSort(arr, 0, size-1);
    std::cout<<"The array after applying Quick Sort is: ";
    for(int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
    return 0 ;
}