#include <iostream>
using namespace std;

const int P = 5; // Number of processes
const int R = 3; // Number of resources

int main() {
    int allocation[P][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int maxNeed[P][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int available[R] = {3, 3, 2};
    int need[P][R];
    bool finish[P] = {false};
    int safeSequence[P];

    // Calculate the need matrix
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = maxNeed[i][j] - allocation[i][j];
        }
    }

    int count = 0;

    while (count < P) {
        bool found = false;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < R; j++) {
                    if (need[i][j] > available[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate) {
                    for (int j = 0; j < R; j++) {
                        available[j] += allocation[i][j];
                    }
                    safeSequence[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "System is not in a safe state." << endl;
            return 0;
        }
    }

    // If system is in a safe state
    cout << "System is in a safe state.\nSafe sequence: ";
    for (int i = 0; i < P; i++) {
        cout << "P" << safeSequence[i];
        if (i != P - 1) cout << " -> ";
    }
    cout << endl;

    return 0;
}
