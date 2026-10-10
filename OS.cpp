//FCFS Scheduling Algorithm
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], ct[n], tat[n], wt[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time for Process " << i + 1 << ": ";
        cin >> at[i];
        cout << "Enter Burst Time for Process " << i + 1 << ": ";
        cin >> bt[i];
    }

    int ct_time = 0, total_tat = 0, total_wt = 0;
    cout << "\nPID AT BT CT TAT WT\n";

    for (int i = 0; i < n; i++) {
        if (ct_time < at[i]) 
            ct_time = at[i];
        ct_time += bt[i];

        ct[i] = ct_time;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_tat += tat[i];
        total_wt += wt[i];

        cout << i + 1 << "    " << at[i] << "  " << bt[i] << "  " << ct[i]
             << "  " << tat[i] << "   " << wt[i] << endl;
    }

    cout << "\nAvg TAT: " << (double)total_tat / n;
    cout << "\nAvg WT: " << (double)total_wt / n << endl;

    return 0;
}
