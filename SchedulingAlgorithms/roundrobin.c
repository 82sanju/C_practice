#include <stdio.h>

int main() {
    int n, tq;
    int burst[10], remaining[10];
    int waiting[10] = {0}, turnaround[10];
    int time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    // Round Robin execution
    while (completed < n) {
        for (int i = 0; i < n; i++) {

            if (remaining[i] > 0) {

                if (remaining[i] > tq) {
                    time += tq;
                    remaining[i] -= tq;
                } 
                else {
                    time += remaining[i];

                    // Completion time = current time
                    turnaround[i] = time;

                    remaining[i] = 0;
                    completed++;
                }
            }
        }
    }

    // Waiting Time = Turnaround Time - Burst Time
    for (int i = 0; i < n; i++) {
        waiting[i] = turnaround[i] - burst[i];
    }

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n",
               i + 1,
               burst[i],
               waiting[i],
               turnaround[i]);
    }

    return 0;
}