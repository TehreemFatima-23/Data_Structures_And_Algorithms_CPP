#include <iostream>
const int SIZE = 5;

class CircularQueue{
    private:
    int front;
    int rear;
    int arr[SIZE];

    public:
    CircularQueue(){
        front = -1;
        rear = -1;
    }
    bool isEmpty(){
        return front == -1;
    }
    bool isFull(){
        return (rear + 1) % SIZE == front; 
    }
    void enqueue(int value){
        if (isFull()){
            std::cout<<"Queue if full\n";
            return;
        }
        else if(isEmpty()){
            front = rear = 0;
            arr[rear] = value;
            std::cout<<"The value inserted is: "<<value<<"\n";
        }
        else{
            rear = (rear + 1) % SIZE;
            arr[rear] = value;
            std::cout<<"The value inserted is "<<value<<"\n";
        }
    }
    void dequeue(){
        if(isEmpty()){
            std::cout<<"Queue is empty\n";
            return;
        }
        else{
            std::cout<<"The value deleted is: "<<arr[front]<<"\n";
            if(rear == front){
                front = rear = -1;
            }
            else{
                front = (front + 1) % SIZE;
            }
        }
    }
    void display(){
        if(isEmpty()){
            std::cout<<"Queue is empty\n";
            return;
        }
        std::cout<<"Circular Queue: ";
        int i = front;
        while(true){
            std::cout<<arr[i]<<" ";
            if(i == rear){
                break;
            }
            i = (i + 1) % SIZE;
        }
        std::cout<<"\n";
    }
};

int main(){
    CircularQueue cq;
    cq.enqueue(15);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(45);
    cq.enqueue(50);

    cq.display();

    cq.dequeue();
    cq.dequeue();

    cq.display();

    cq.enqueue(65);
    cq.enqueue(70);

    cq.display();
    return 0;
}