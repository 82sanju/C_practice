#include <stdio.h>

int main() {

    int n = 3;
    int bursttime[] = {5, 3, 2};

    int WaitTime[3], turnOverTime[3];

    WaitTime[0] = 0;

    for (int i = 1; i < n; i++) {

        WaitTime[i] = WaitTime[i-1] + bursttime[i-1];
    }

    for (int i = 0; i < n; i++) {
        turnOverTime[i] = WaitTime[i] + bursttime[i];\

    }
    for (int i = 0; i < n; i++) {
        printf("Process%d WaitTime=%d TurnOverTime=%d\n", i+1, WaitTime[i], turnOverTime[i]);
    }

    return 0;
}