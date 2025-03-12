#include <stdio.h>

int arr[5], bt[5], wt[5], tat[5], pid[5], ct[5];
int totalwt = 0, totaltat = 0, n = 5;

void main() {
    printf("Enter the Arrival times for 5 processes:\n");
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the Burst times for 5 processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }

    int completed = 0, time = 0;
    int is_completed[5] = {0};

    while (completed != n) {
        int idx = -1, min_bt = 9999;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= time && !is_completed[i] && bt[i] < min_bt) {
                min_bt = bt[i];
                idx = i;
            }
        }

        if (idx != -1) {
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - arr[idx];
            wt[idx] = tat[idx] - bt[idx];
            totalwt += wt[idx];
            totaltat += tat[idx];
            is_completed[idx] = 1;
            completed++;
        } else {
            time++;
        }
    }

    printf("\nProcess ID | Arrival Time | Burst Time | Waiting Time | Turnaround Time | Completion Time\n");
    for (int i = 0; i < n; i++) {
        printf("    %d      |      %d      |     %d     |      %d      |       %d        |       %d\n",
               pid[i], arr[i], bt[i], wt[i], tat[i], ct[i]);
    }
    printf("Average Waiting Time: %.2f\n", (float)totalwt / n);
    printf("Average Turnaround Time: %.2f\n", (float)totaltat / n);
}
