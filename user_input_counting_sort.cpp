#include <iostream>
using namespace std;

void countingSort(int arr[], int size) {
    // Step 1: Find the maximum element
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Step 2: Create count array and initialize to 0
    int count[100] = {0}; // Works for numbers from 0 to 99

    // Step 3: Count occurrences
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    // Step 4: Rebuild the sorted array
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}

int main() {
    int arr[100], size;

    // Get the number of elements
    cout << "Enter number of elements: ";
    cin >> size;

    // Get the elements from user
    cout << "Enter " << size << " elements (0 to 99): ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Sort the array
    countingSort(arr, size);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
