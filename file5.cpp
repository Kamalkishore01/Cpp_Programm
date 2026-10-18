#include <iostream>
using namespace std;

// The function will sort arry[] of size m using Bubble Sort
void BubbleSort(int arry[], int m) {
    int i, j;
    for (i = 0; i < m; ++i) {
        // Create boolean variable swapped and initialize it with false
        bool swapped = false;
        for (j = 0; j < m - i - 1; ++j) {
            // Comparing consecutive elements and switching values when value at j > j+1
            if (arry[j] > arry[j + 1]) {
                arry[j] = arry[j] + arry[j + 1];
                arry[j + 1] = arry[j] - arry[j + 1];
                arry[j] = arry[j] - arry[j + 1];
                // Its value becomes true if swapping takes place
                swapped = true;
            }
        }
        // Checking the value of swapped
        if (!swapped)
            break;
    }
}

// Main method
int main() {
    int m, i;
    cout << "\nEnter the total number of elements to be sorted: ";
    cin >> m;

    int arry[m];
    for (i = 0; i < m; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arry[i];
    }

    // Call BubbleSort() function with arry[] of size m
    BubbleSort(arry, m);

    // Display the sorted array
    cout << "\nSorted Array is: ";
    for (i = 0; i < m; i++)
        cout << "->" << arry[i];

    cout << endl;
    return 0;
}
