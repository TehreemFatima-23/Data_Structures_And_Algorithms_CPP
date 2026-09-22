#include <iostream>

// Function to handle linear probing insertion
void insert(int hashTable[], int size, int key)
{
    int index = key % size;

    while(hashTable[index] != -1)
    {
        index = (index + 1) % size;
    }

    hashTable[index] = key;
}

int main()
{
    int hashTable[10];

    // Initialize all positions as empty (-1)
    for(int i = 0; i < 10; i++)
    {
        hashTable[i] = -1;
    }

    insert(hashTable, 10, 12);
    insert(hashTable, 10, 32);
    insert(hashTable, 10, 52);

    // Display the hash table
    for(int i = 0; i < 10; i++)
    {
        std::cout << "Index " << i << " stores value: " << hashTable[i] << "\n";
    }

    return 0;
}