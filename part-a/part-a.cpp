#include <algorithm>
#include <cstddef>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

// Function prototype for the recursive function.
template <typename T>
T findMaxRecTail(const T arr[], const int SIZE, int i, T max_val);

// The helper function to simplify the initial call.
template <typename T>
T findMax(const T arr[], const int SIZE) {
    if (SIZE == 0) {
        // Handle an empty array case.
        return T(); 
    }
    return findMaxRecTail(arr, SIZE, 0, arr[0]);
}

// Function that finds the maximum value using tail recursion.
template <typename T>
T findMaxRecTail(const T arr[], const int SIZE, int i, T max_val) {
    // Base case: We've reached the end of the array.
    if (i == SIZE) {
        return max_val;
    }

    // Recursive step: Update the max_val if the current element is greater.
    if (arr[i] > max_val) {
        max_val = arr[i];
    }

    // Tail call: The recursive call is the last operation.
    return findMaxRecTail(arr, SIZE, i + 1, max_val);
}

int main() {
    // Create the array
    const int SIZE = 10;
    int my_array[SIZE] = {5, 23, 0, -2, 4, 9, 11, 21, 130, 6};

    // Display the maximum using recursion
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Recursion: " << findMax(my_array, SIZE) << endl;
    cout << "Should be 130 for the fixed array\n" << endl;
    cout << setfill('-') << setw(40) << "" << endl;

    // Create a random array
    const int SIZE_2 = 1000;
    const int MAX_VAL = 10000;
    int rand_array[SIZE_2];
    srand(time(0));
    for (int &elem : rand_array) {
        elem = rand() % MAX_VAL;
    }

    // Find the maximum using C++ standard's algorithm
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Standard Algorithm: " << endl;
    cout << " " << *max_element(rand_array, rand_array + SIZE_2) << endl;
    cout << setfill('-') << setw(40) << "" << endl;

    // Find the maximum using the recursive implementation
    cout << "Maximum using Recursion: " << findMax(rand_array, SIZE_2) << endl;
    cout << setfill('-') << setw(40) << "" << endl;

    return 0;
}