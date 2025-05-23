#include <stdio.h>
#include <stdlib.h>


int arr[5];
int bt[5];
int wt[5];
int ct[5];
int tat[5];
int pid[5];  
int totalwt = 0;
int totaltat = 0;
int time = 0;
int i = 0;


void main() {
    printf("Enter the Arrival times for 5 processes:\n");
    for (i = 0; i < 5; i++) {
        pid[i] = i + 1;  
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &arr[i]);
    }


    printf("Enter the Burst times for 5 processes:\n");
    for (i = 0; i < 5; i++) {
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }


    for (i = 0; i < 5; i++) {
        wt[i] = 0;
        tat[i] = 0;
    }


    for (i = 0; i < 5 - 1; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (arr[i] > arr[j]) {
               
                int temp_arr = arr[i];
                arr[i] = arr[j];
                arr[j] = temp_arr;


               
                int temp_bt = bt[i];
                bt[i] = bt[j];
                bt[j] = temp_bt;


               
                int temp_pid = pid[i];
                pid[i] = pid[j];
                pid[j] = temp_pid;
            }
        }
    }


    for (i = 0; i < 5; i++) {
        if (i == 0) {
            time = arr[i] + bt[i];
            ct[i]=time;
            tat[i] = bt[i];
            wt[i] = 0;
        } else {
            if (arr[i] > time) {
                time = arr[i] + bt[i];
                ct[i]=time;
                tat[i] = bt[i];
                wt[i] = 0;
            } else {
                tat[i] = time - arr[i] + bt[i];
                wt[i] = time - arr[i];
                time = time + bt[i];
                ct[i]=time;
            }
        }
        totalwt += wt[i];
        totaltat += tat[i];
    }


    printf("\nProcess ID  |  Arrival Time  |  Burst Time  | Completion Time  |  Waiting Time  |  Turnaround Time\n");
    for (i = 0; i < 5; i++) {
        printf("    %d       |       %d        |      %d       |       %d        |      %d         |        %d\n",
                pid[i], arr[i], bt[i],ct[i], wt[i], tat[i]);
    }


    printf("\nTotal Waiting Time: %d\n", totalwt);
    printf("Total Turnaround Time: %d\n", totaltat);
    printf("Average Waiting Time: %.2f\n", (float)totalwt / 5);
    printf("Average Turnaround Time: %.2f\n", (float)totaltat / 5);
}



