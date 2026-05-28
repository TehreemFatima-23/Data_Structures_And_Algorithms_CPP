#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target)
            return i;
    }
    return -1;
}


int main(){
    int target;
    int numbers[] = {50, 60, 40, 10, 20};

    int size = sizeof(numbers)/sizeof(numbers[0]);

    cout<<"Elements in Array: ";
    for (int i=0; i<size; i++){
        cout<<numbers[i]<<" ";
    }
    cout<<endl;

    cout<<"Number you want to search: ";
    cin>>target;
    int result = linearSearch(numbers, size, target);

    if(result!=-1){
        cout<<"Element "<<target<<" found at index "<<result<<endl;
    }
    else{
        cout<<"Element "<<target<<" not found here"<<endl;
    }


    return 0;
}