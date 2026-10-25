// SJF Non preemption
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n], wt[n], tat[n], p[n], at[n], ct[n];

    // Input arrival times and burst times
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        cout << "Enter Arrival Time for Process " << p[i] << ": ";
        cin >> at[i];
        cout << "Enter Burst Time for Process " << p[i] << ": ";
        cin >> bt[i];
    }

    // Sort processes based on arrival time, then burst time (if arrival time is equal)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j] || (at[i] == at[j] && bt[i] > bt[j])) {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    // Calculate Waiting Time (WT) and Completion Time (CT)
    int current_time = at[0];
    wt[0] = 0;
    ct[0] = at[0] + bt[0];

    for (int i = 1; i < n; i++) {
        current_time += bt[i - 1];
        if (current_time < at[i]) {
            current_time = at[i];
        }
        wt[i] = current_time - at[i];
        ct[i] = current_time + bt[i];
    }

    // Calculate Turnaround Time (TAT)
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Display results
    cout << "\nID\tAT\tBT\tWT\tTAT\tCT\n";
    for (int i = 0; i < n; i++) {
        cout << p[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << wt[i]
             << "\t" << tat[i] << "\t" << ct[i] << endl;
    }


    // Calculate Average Waiting Time and Average Turnaround Time
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    cout << "\nAverage Waiting Time: " << avg_wt / n << endl;
    cout << "Average Turnaround Time: " << avg_tat / n << endl;

    return 0;
}
