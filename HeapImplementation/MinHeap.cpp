#include <iostream>

class MinHeap{
    int arr[100];
    int size;
    public:
    MinHeap(){
        size = 0;
    }
    void insert(int value){
        arr[size] = value;
        int i = size;
        size++;
        //Heapify up
        while(i != 0){
            int parent = (i-1)/2;
            if(arr[i]<arr[parent]){
                std::swap(arr[i], arr[parent]);
                i = parent;
            }
            else{
                break;
            }
        }
    }
    void deleteRoot(){
        if(size == 0){
            std::cout<<"Min Heap Tree is empty\n";
            return;
        }
        arr[0]=arr[size-1];
        size--;
        int i = 0;
        //Heapify down
        while(true){
            int left = 2*i+1;
            int right = 2*i+2;
            int smallest = i;
            if(left<size && arr[left]<arr[smallest]){
                smallest = left;
            }
            if(right<size && arr[right]<arr[smallest]){
                smallest = right;
            }
            if(smallest != i){
                std::swap(arr[i], arr[smallest]);
                i = smallest;
            }
            else{
                break;
            }
        }
    }
    void display(){
        if(size == 0){
            std::cout<<"Min Heap Tree is empty\n";
            return;
        }
        for(int i = 0; i<size; i++){
            std::cout<<arr[i]<<" ";
        }
        std::cout<<"\n";
    }
};
int main(){
    MinHeap mh;
    mh.insert(4);
    mh.insert(20);
    mh.insert(10);
    mh.insert(13);
    mh.insert(22);

    std::cout<<"Min Heap Tree is: ";
    mh.display();

    mh.deleteRoot();
    std::cout<<"Min Heap Tree after deleting root is: ";
    mh.display();

    return 0;
}