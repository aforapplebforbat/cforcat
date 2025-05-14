#include <stdio.h>

typedef struct {
    int pid, bt, priority, wt, tat;
} Process;

int main() {
    int n;
    Process p[10], temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Burst Time and Priority for P%d: ", p[i].pid);
        scanf("%d %d", &p[i].bt, &p[i].priority);
    }

    // Sort by priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].wt = 0;
    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }

    float avgWT = 0, avgTAT = 0;
    printf("\nP\tBT\tPriority\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].wt + p[i].bt;
        avgWT += p[i].wt;
        avgTAT += p[i].tat;
        printf("P%d\t%d\t%d\t\t%d\t%d\n", p[i].pid, p[i].bt, p[i].priority, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time: %.2f", avgWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT / n);
    return 0;
}

