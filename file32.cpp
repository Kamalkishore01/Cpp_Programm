#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int arrival[n], burst[n], priority[n], remaining[n], completion[n];
    int waiting[n], turnaround[n], completed = 0, time = 0;
    float totalWT = 0, totalTAT = 0; // For average calculations

    cout << "Enter Arrival Time, Burst Time, and Priority (lower number = higher priority):\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> arrival[i] >> burst[i] >> priority[i];
        remaining[i] = burst[i];
    }

    while (completed < n) {
        int minPriority = INT_MAX, index = -1;

        for (int i = 0; i < n; i++) {
            if (arrival[i] <= time && remaining[i] > 0 && priority[i] < minPriority) {
                minPriority = priority[i];
                index = i;
            }
        }

        if (index == -1) {
            time++;
            continue; // If no process is ready, move time forward
        }

        // Execute the selected process for 1 time unit
        remaining[index]--;

        // If the process finishes
        if (remaining[index] == 0) {
            completion[index] = time + 1;
            turnaround[index] = completion[index] - arrival[index];
            waiting[index] = turnaround[index] - burst[index];
            totalWT += waiting[index];
            totalTAT += turnaround[index];
            completed++;
        }

        time++;
    }

    // Output the results
    cout << "\nProcess\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << arrival[i] << "\t" << burst[i] << "\t" << priority[i]
             << "\t\t" << completion[i] << "\t\t" << turnaround[i] << "\t\t" << waiting[i] << "\n";
    }

    // Average Times
    cout << "\nAverage Waiting Time: " << (totalWT / n);
    cout << " ms\nAverage Turnaround Time: " << (totalTAT / n) << " ms\n";

    return 0;
}
