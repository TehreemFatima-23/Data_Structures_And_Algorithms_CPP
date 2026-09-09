#include <iostream>

class Queue{
    int arr[100];
    int front;
    int rear;
    public:
    Queue(){
        front = 0;
        rear = -1;
    }
    void push(int value){
        rear++;
        arr[rear] = value;
    }
    int pop(){
        int value = arr[front];
        front++;
        return value;
    }
    bool empty(){
        return front>rear;
    }
};
int main(){
    int graph[6][6] = {0};
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[1][3] = 1;
    graph[3][1] = 1;
    graph[2][4] = 1;
    graph[4][2] = 1;
    graph[2][5] = 1;
    graph[5][2] = 1;
    graph[3][6] = 1;
    graph[6][3] = 1;

    bool visited[7] = {false};

    Queue q;
    q.push(1);
    visited[1] = true;

    std::cout<<"BFS traversal is: ";
    while(!q.empty()){
        int current = q.pop();
        std::cout<<current<<" ";
         // Check all neighbors
        for (int i = 1; i <= 6; i++)
        {
            if (graph[current][i] == 1 && visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return 0;
}