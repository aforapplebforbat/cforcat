#include <stdio.h>

int findOptimal(int pages[], int frames[], int n, int f, int index) {
    int farthest = index, result = -1;
    int i, j;

    for (i = 0; i < f; i++) {
        int found = 0;
        for (j = index; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    result = i;
                }
                found = 1;
                break;
            }
        }
        if (!found)
            return i;
    }

    return result == -1 ? 0 : result;
}

int main() {
    int pages[100], frames[10], n, f, i, j, count = 0, found;

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
            int pos = -1;
            for (j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if (pos == -1)
                pos = findOptimal(pages, frames, n, f, i + 1);

            frames[pos] = pages[i];
            count++;
        }
    }

    printf("Page faults = %d\n", count);
    return 0;
}

