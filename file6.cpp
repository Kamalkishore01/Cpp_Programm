//Round robin

#include <iostream>
using namespace std;

int main() {
    int n, time_quantum;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the time quantum: ";
    cin >> time_quantum;

    int arrival_time[n], burst_time[n], remaining_time[n];
    int completion_time[n], turnaround_time[n], waiting_time[n];

    // Input process data
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> arrival_time[i] >> burst_time[i];
        remaining_time[i] = burst_time[i];
    }

    int current_time = 0, completed = 0;

    while (completed < n) {
        bool all_idle = true;

        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0 && arrival_time[i] <= current_time) {
                all_idle = false;

                if (remaining_time[i] > time_quantum) {
                    remaining_time[i] -= time_quantum;
                    current_time += time_quantum;
                } else {
                    current_time += remaining_time[i];
                    remaining_time[i] = 0;
                    completion_time[i] = current_time;
                    turnaround_time[i] = completion_time[i] - arrival_time[i];
                    waiting_time[i] = turnaround_time[i] - burst_time[i];
                    completed++;
                }
            }
        }

        if (all_idle) current_time++;
    }

    // Display results
    float total_wt = 0, total_tat = 0;

    cout << "\n";
    cout << "P\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "---------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << arrival_time[i] << "\t" << burst_time[i] << "\t"
             << completion_time[i] << "\t" << turnaround_time[i] << "\t" << waiting_time[i] << endl;
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
    }

    cout << "\nAverage Waiting Time: " << total_wt / n << endl;
    cout << "Average Turnaround Time: " << total_tat / n << endl;

    return 0;
}
