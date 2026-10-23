#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // for std::setprecision
using namespace std;

struct Process {
    string pid;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

bool compareArrival(Process a, Process b) {
    return a.arrivalTime < b.arrivalTime;
}

void calculateFCFS(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), compareArrival);

    int n = processes.size();
    int currentTime = 0;
    double totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime; // CPU idle time
        }

        processes[i].completionTime = currentTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;

        totalWT += processes[i].waitingTime;
        totalTAT += processes[i].turnaroundTime;

        currentTime = processes[i].completionTime;
    }

    // Print the results
    cout << "PID\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n";
    for (const auto& p : processes) {
        cout << p.pid << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t"
             << p.completionTime << "\t\t" << p.waitingTime << "\t" << p.turnaroundTime << endl;
    }

    // Print average waiting and turnaround time
    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << (totalWT / n) << endl;
    cout << "Average Turnaround Time: " << (totalTAT / n) << endl;
}

int main() {
    vector<Process> processes = {
        {"P1", 0, 4},
        {"P2", 1, 3},
        {"P3", 2, 1},
        {"P4", 3, 2}
    };

    calculateFCFS(processes);
    return 0;
}
