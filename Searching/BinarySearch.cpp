#include <iostream>
using namespace std;

int main() {
    // Sorted array
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = 10; 
    
    int target = 20; // The number we want to find
    
    int low = 0;
    int high = n - 1; 
    int result = -1;  

    while (low <= high) {
        int mid = (low + high) / 2; // Find the middle index

        if (arr[mid] == target) {
            result = mid; 
            break;        
        }
        else if (arr[mid] < target) {
            low = mid + 1; // Target is in the right half
        }
        else {
            high = mid - 1; // Target is in the left half
        }
    }

    // 4. Print the result
    if (result != -1) {
        cout << "Found " << target << " at index " << result << endl;
    } else {
        cout << "Number not found " << endl;
    }

    return 0;
}