#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int arrival[n], burst[n], priority[n], completion[n];
    int waiting[n], turnaround[n], start[n], completed[n] = {0};
    float totalWT = 0, totalTAT = 0;

    cout << "Enter Arrival Time, Burst Time, and Priority (lower number = higher priority):\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> arrival[i] >> burst[i] >> priority[i];
        completed[i] = 0; // Initialize completion flags
    }

    int completedProcesses = 0, currentTime = 0;

    while (completedProcesses < n) {
        int minPriority = INT_MAX, index = -1;

        // Find the highest priority process that has arrived and is not completed
        for (int i = 0; i < n; i++) {
            if (!completed[i] && arrival[i] <= currentTime && priority[i] < minPriority) {
                minPriority = priority[i];
                index = i;
            }
        }

        if (index == -1) {
            currentTime++;
            continue; // If no process is ready, move time forward
        }

        start[index] = currentTime; // Process starts execution
        completion[index] = currentTime + burst[index]; // Process completion time
        turnaround[index] = completion[index] - arrival[index]; // Turnaround Time
        waiting[index] = turnaround[index] - burst[index]; // Waiting Time

        totalWT += waiting[index];
        totalTAT += turnaround[index];
        completed[index] = 1;
        completedProcesses++;
        currentTime = completion[index]; // Move time forward
    }

    cout << "\nProcess\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << arrival[i] << "\t" << burst[i] << "\t" << priority[i]
             << "\t\t" << completion[i] << "\t\t" << turnaround[i] << "\t\t" << waiting[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << (totalWT / n);
    cout << "\nAverage Turnaround Time: " << (totalTAT / n) << endl;

    return 0;
}
