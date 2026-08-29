#include <iostream>
const int SIZE = 5;

class PriorityQueue{
    private:
    int arr[SIZE];
    int rear;
    public:
    PriorityQueue(){
        rear = -1;
    }
    void enqueue(int value){
        if(rear ==  SIZE-1){
            std::cout<<"Priority Queue is full\n";
            return;
        }
        rear++;
        int i = rear-1;
        //Shifting smaller elements to the right
        while(i>=0 && arr[i]<value){
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=value;
    }
    void dequeue(){
        if(rear==-1){
            std::cout<<"Priority Queue is empty\n";
            return;
        }
        else{
            std::cout<<"The element deleted from priority queue is: "<<arr[0]<<"\n";

            for(int i=0; i<rear; i++){
                arr[i] = arr[i+1];
            }
            rear--;
        }
    }
    void display(){
        if(rear == -1){
            std::cout<<"Priority Queue is empty\n";
        }
        else{
            std::cout<<"Priority Queue is: ";
            for(int i=0; i<=rear; i++){
                std::cout<<arr[i]<<" ";
            }
            std::cout<<"\n";
        }
    }
};

int main(){
    PriorityQueue pq;

    pq.enqueue(25);
    pq.enqueue(10);
    pq.enqueue(56);
    pq.enqueue(35);

    pq.display();

    pq.dequeue();
    pq.dequeue();

    pq.display();

    return 0;
}