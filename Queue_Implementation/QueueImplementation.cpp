#include <iostream>

const int SIZE = 4;

class Queue{
    private:
    int arr[SIZE];
    int front;
    int rear;

    public:
    Queue(){
        front = -1;
        rear = -1;
    }
    void insertInQueue(int value){
        if(rear==SIZE-1){
            std::cout<<"Queue overflow\n";
        }
        else{
            if(front==-1){
                front = 0;
            }
            rear++;
            arr[rear] = value;
            std::cout<<"The value inserted in the queue is: "<<value<<"\n";
        }
    }
    void deleteFromQueue(){
        if(front==-1 || front>rear){
            std::cout<<"Queue underflow\n";
        }
        else{
            std::cout<<"The value deleted from queue is: "<<arr[front]<<"\n";
            front++;
        }
    }
    void display(){
        if(front==-1 || front>rear){
            std::cout<<"Queue is empty\n";
        }
        else{
            std::cout<<"Queue is: ";
            for(int i=front; i<=rear; i++){
                std::cout<<arr[i]<<" ";
            }
            std::cout<<"\n";
        }
    }
};
int main(){
    Queue var;
    var.insertInQueue(3);
    var.insertInQueue(6);
    var.insertInQueue(9);
    var.display();
    var.deleteFromQueue();
    var.deleteFromQueue();
    var.display();
    var.insertInQueue(12);
    var.insertInQueue(15);
    var.display();
    return 0;
}