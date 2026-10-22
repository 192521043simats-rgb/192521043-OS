#include <stdio.h>
int main() {
    int n, q, i, time = 0, done, bt[10], rt[10];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
    printf("Enter time quantum: ");
    scanf("%d", &q);
    do {
        done = 1;
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                done = 0;

                if(rt[i] > q) {
                    time += q;
                    rt[i] -= q;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                }

                printf("P%d ", i + 1);
            }
        }
    } while(!done);
    printf("\nTotal time: %d", time);
    return 0;
}