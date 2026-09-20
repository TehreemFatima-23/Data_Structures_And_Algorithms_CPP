#include <iostream>

void merge(int arr[], int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int temp[100];
    int k = 0;

    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j<=high){
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(int final=0; final<k; final++){
        arr[low + final] = temp[final];
    }
}
void mergeSort(int arr[], int low, int high){
    if(low<high){
        int mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}
int main(){
    int size = 6;
    int arr[size];
    std::cout<<"Enter the elements that need to be sorted using Merge Sort: ";
    for(int i=0; i<size; i++){
        std::cin>>arr[i];
    }
    mergeSort(arr, 0, size-1);
    std::cout<<"The elements of the array after applying Merge Sort are: ";
    for(int i=0; i<size; i++){
        std::cout<<arr[i]<<" ";
    }
    return 0;
}