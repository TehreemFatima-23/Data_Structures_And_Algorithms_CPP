#include <iostream>
using namespace std;

const int SIZE = 6;
int stackArr[SIZE];
int top = -1;

void push(int value){
    if (top == SIZE - 1){
        cout<<"Stack overflow"<<endl;
    }
     else{
            top++;
            stackArr[top] = value;
            cout<<"Value inserted: "<<value<<endl;
            
        }
}

void pop(){
    if(top == -1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        int temp = stackArr[top];
        cout<<temp<<" Value deleted"<<endl;
        top--;
    }
}

void display(){
    if(top == -1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack array: "<<endl;
        for(int i=top; i>=0; i--){
            cout<<stackArr[i]<<endl;
        }
    }
}

int main(){

    //pushing values into the stack
    push(30);
    push(50);
    push(15);
    push(55);

    display();

    pop();//delete values from the stack
    pop();

    display();

    return 0;
}
