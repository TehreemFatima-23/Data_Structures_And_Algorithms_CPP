#include <iostream>

void heapify(int arr[], int size, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<size && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<size && arr[right]>arr[largest]){
        largest = right;
    }
    if(largest != i){
        std::swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}
void heapSort(int arr[], int size){
    // Build max heap
    for(int i=size/2-1; i>=0; i--){
        heapify(arr, size, i);
    }
    //Move largest element to the end
    for(int i = size-1; i>0; i--){
        std::swap(arr[0], arr[i]);
        //Fix the remaining heap
        heapify(arr, i, 0);
    }
}
int main(){
    int size = 5;
    int arr[size] ;
    
    std::cout<<"Original Heap Array is: ";
    for(int i=0; i<size; i++){
        std::cin>>arr[i];
    }
    heapSort(arr, size);
    std::cout<<"Sorted Heap Array is: ";
    for(int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
    return 0;
}