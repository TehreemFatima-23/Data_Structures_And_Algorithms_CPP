#include <iostream>

class MaxHeap{
    int arr[100];
    int size;
    public:
    MaxHeap(){
        size = 0;
    }
    void insert(int value){
        arr[size] = value;
        int i = size;
        size++;
        //Heapify up
        while (i != 0)
        {
            int parent = (i-1)/2;
            if(arr[parent]<arr[i]){
                std::swap(arr[parent], arr[i]);
                i = parent;
            }
            else{
                break;
            }
        }
    }
    void deleteRoot()
    {
        if (size == 0)
        {
            std::cout << "Heap is empty\n";
            return;
        }

        // Move last element to root
        arr[0] = arr[size - 1];
        size--;

        // Heapify Down
        int i = 0;

        while (true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            int largest = i;

            if (left < size && arr[left] > arr[largest])
            {
                largest = left;
            }

            if (right < size && arr[right] > arr[largest])
            {
                largest = right;
            }

            if (largest != i)
            {
                std::swap(arr[i], arr[largest]);
                i = largest;
            }
            else
            {
                break;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }

        std::cout << "\n";
    }
};

int main()
{
    MaxHeap h;

    h.insert(80);
    h.insert(35);
    h.insert(48);
    h.insert(70);
    h.insert(90);

    std::cout << "Max Heap: ";
    h.display();

    h.deleteRoot();

    std::cout << "After deleting root: ";
    h.display();

    return 0;
}