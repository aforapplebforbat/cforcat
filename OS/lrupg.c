#include <stdio.h>

int main() {
    int pages[100], frames[10], time[10], n, f, i, j, pos, count = 0, min, t = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page sequence:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for (i = 0; i < n; i++) {
        found = 0;

        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                time[j] = t++;
                break;
            }
        }

        if (!found) {
            pos = 0;
            min = time[0];
            for (j = 1; j < f; j++) {
                if (time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            time[pos] = t++;
            count++;
        }
    }

    printf("Page faults = %d\n", count);
    return 0;
}

