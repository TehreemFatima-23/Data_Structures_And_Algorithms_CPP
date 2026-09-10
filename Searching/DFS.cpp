#include <iostream>

int graph[6][6] = {0};
bool visited[7] = {false};

void DFS(int current){
    visited[current] = true;
    std::cout<<current<<" ";
    for(int i=1; i<=6; i++){
        if(graph[current][i]==1 && visited[i]==false){
            DFS(i);
        }
    }
}
int main(){
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
    std::cout<<"DFS Traversal is: ";
    DFS(1);
    return 0;
}