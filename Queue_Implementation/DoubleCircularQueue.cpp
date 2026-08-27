#include <iostream>
const int SIZE = 5;

class Deque{
    private:
    int arr[SIZE];
    int front;
    int rear;
    public:
    Deque(){
        front = -1;
        rear = -1;
    }
    bool isFull(){
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }
    bool isEmpty(){
        return (front == -1);
    }
    void insertFront(int value){
        if(isFull()){
            std::cout<<"Double ended Queue is full\n";
        }
        else if(isEmpty()){
            front = rear = 0;
            arr[front] = value;
        }
        else if(front == 0){
            front = SIZE - 1;
            arr[front] = value;
        }
        else{
            front --;
            arr[front] = value;
        }
    }
    void insertRear(int value){
        if(isFull()){
            std::cout<<"Double ended Queue is full\n";
        }
        else if(isEmpty()){
            front = rear = 0;
            arr[rear] = value;
        }
        else if(rear == SIZE - 1){
            rear = 0;
            arr[rear] = value;
        }
        else{
            rear ++;
            arr[rear] = value;
        }
    }
        void deleteFront(){
            if(isEmpty()){
                std::cout<<"Double ended Queue is empty\n";
            }
            else {
                std::cout<<"The value deleted is: "<<arr[front]<<"\n";
                if(front == rear){
                    front = rear = -1;
                }
                else if(front == SIZE - 1){
                    front = 0;
                }
                else{
                    front ++;
                }
            }
        }
        void deleteRear(){
            if(isEmpty()){
                std::cout<<"Double ended Queue is empty\n";
            }
            else{
                std::cout<<"The value deleted is "<<arr[rear]<<"\n";
                if(rear == front){
                    rear = front = -1;
                }
                else if(rear == 0){
                    rear = SIZE - 1;
                }
                else{
                    rear --;
                }
            }
        }
        void display(){
            if(isEmpty()){
                std::cout<<"Double ended Queue is empty\n";
                return;
            }
            std::cout<<"Double ended circular Queue: ";
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
    Deque dq;
    dq.insertRear(45);
    dq.insertRear(80);
    dq.insertFront(67);
    dq.display();
    dq.deleteFront();
    dq.deleteRear();
    dq.display();
    dq.insertFront(50);
    dq.insertRear(70);
    dq.display();
return 0;
}