#include <stdio.h>

int main() {
    int pages[100], frames[10], n, f, i, j, k = 0, count = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page sequence:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) frames[i] = -1;

    for (i = 0; i < n; i++) {
        found = 0;

        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[k] = pages[i];
            k = (k + 1) % f;
            count++;
        }
    }

    printf("Page faults = %d\n", count);
    return 0;
}

