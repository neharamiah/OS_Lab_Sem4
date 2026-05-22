#include <stdio.h>

int main() {
    int ref[20], n, f;
    int i, j, k;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &ref[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // FIFO
    int fifo[10], fifoFault = 0, index = 0, found;

    for(i = 0; i < f; i++)
        fifo[i] = -1;

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < f; j++) {
            if(fifo[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        if(found == 0) {
            fifo[index] = ref[i];
            index = (index + 1) % f;
            fifoFault++;
        }
    }

    // LRU
    int lru[10], time[10], lruFault = 0;
    int pos, least;

    for(i = 0; i < f; i++) {
        lru[i] = -1;
        time[i] = -1;
    }

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < f; j++) {
            if(lru[j] == ref[i]) {
                found = 1;
                time[j] = i;
                break;
            }
        }

        if(found == 0) {
            least = time[0];
            pos = 0;

            for(j = 1; j < f; j++) {
                if(time[j] < least) {
                    least = time[j];
                    pos = j;
                }
            }

            lru[pos] = ref[i];
            time[pos] = i;
            lruFault++;
        }
    }

    // Optimal
    int opt[10], optFault = 0;
    int farthest;

    for(i = 0; i < f; i++)
        opt[i] = -1;

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < f; j++) {
            if(opt[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        if(found == 0) {

            for(j = 0; j < f; j++) {
                if(opt[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if(j == f) {
                farthest = -1;

                for(j = 0; j < f; j++) {
                    int next = -1;

                    for(k = i + 1; k < n; k++) {
                        if(opt[j] == ref[k]) {
                            next = k;
                            break;
                        }
                    }

                    if(next == -1) {
                        pos = j;
                        break;
                    }

                    if(next > farthest) {
                        farthest = next;
                        pos = j;
                    }
                }
            }

            opt[pos] = ref[i];
            optFault++;
        }
    }

    printf("\nFIFO Page Faults = %d", fifoFault);
    printf("\nLRU Page Faults = %d", lruFault);
    printf("\nOptimal Page Faults = %d", optFault);

    return 0;
}
