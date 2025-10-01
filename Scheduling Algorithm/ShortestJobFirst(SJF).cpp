#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;        // Process ID
    int bt;         // Burst Time
    int at;         // Arrival Time
    int wt;         // Waiting Time
    int tat;        // Turnaround Time
    int ct;         // Completion Time
};

// Comparator for sorting by arrival time
bool compareAT(Process a, Process b) {
    return a.at < b.at;
}

// SJF Non-preemptive Scheduling with Arrival Time
void SJF(vector<Process> &processes) {
    int n = processes.size();
    sort(processes.begin(), processes.end(), compareAT);

    int time = 0, completed = 0;
    vector<bool> done(n, false);

    while (completed < n) {
        // Find process with min burst time among arrived
        int idx = -1, minBT = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!done[i] && processes[i].at <= time) {
                if (processes[i].bt < minBT) {
                    minBT = processes[i].bt;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            // No process has arrived, CPU is idle
            time++;
        } else {
            // Execute the process
            time += processes[idx].bt;
            processes[idx].ct = time;
            processes[idx].tat = processes[idx].ct - processes[idx].at;
            processes[idx].wt = processes[idx].tat - processes[idx].bt;
            done[idx] = true;
            completed++;
        }
    }

    // Output
    double avgWT = 0, avgTAT = 0;
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t" << processes[i].at << "\t"
             << processes[i].bt << "\t" << processes[i].ct << "\t"
             << processes[i].tat << "\t" << processes[i].wt << "\n";
        avgWT += processes[i].wt;
        avgTAT += processes[i].tat;
    }
    cout << "\nAverage Waiting Time: " << (avgWT / n);
    cout << "\nAverage Turnaround Time: " << (avgTAT / n) << "\n";
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<Process> processes(n);

    cout << "Enter Process ID, Arrival Time, and Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        cin >> processes[i].pid >> processes[i].at >> processes[i].bt;
    }

    cout << "\n--- Shortest Job First (SJF) Scheduling ---\n";
    SJF(processes);

    return 0;
}
