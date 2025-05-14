#include <stdio.h>

#define MAX 10

int main() {
    int at[MAX], bt[MAX], rt[MAX];
    int n, time = 0, smallest, count = 0, finish_time;
    float avgWT = 0, avgTAT = 0;
    int wt[MAX], tat[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    rt[9] = 9999; // Sentinel value

    while (count != n) {
        smallest = 9;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0) {
                smallest = i;
            }
        }

        rt[smallest]--;
        time++;

        if (rt[smallest] == 0) {
            count++;
            finish_time = time;
            tat[smallest] = finish_time - at[smallest];
            wt[smallest] = tat[smallest] - bt[smallest];
            avgWT += wt[smallest];
            avgTAT += tat[smallest];
        }
    }

    printf("\nP\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avgWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT / n);
    return 0;
}

