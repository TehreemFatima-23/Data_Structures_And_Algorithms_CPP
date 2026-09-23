#include <iostream>

const int SIZE = 10;
int hashTable[SIZE];
void insert(int key){
    int hash = key % SIZE;
    for(int i=0; i<SIZE; i++){
        int index = (hash + i*i) % SIZE;
        if(hashTable[index] == -1){
            hashTable[index] = key;
            return;
        }
    }
    std::cout<<"Hash Table is full\n";
}

void display(){
    for(int i = 0; i<SIZE; i++){
        std::cout<<"Index "<<"[ "<<i<<" ]"<<" contains the value: "<<hashTable[i]<<"\n";
    }
}
int main(){
    for(int i=0; i<SIZE; i++){
        hashTable[i] = -1;
    }
    insert(55);
    insert(25);
    insert(15);
    insert(75);
    insert(95);
    display();
    return 0;
}