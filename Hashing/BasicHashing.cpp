#include <iostream>

int main(){
    int hashTable[10];
    int key ;
    std::cout<<"Enter the Key: ";
    std::cin>>key;
    int index = key % 10;
    hashTable[index] = key;
    std::cout<<"Key"<<" ["<<key<<"] "<<"is stored at index: "<<index;
    return 0;
}