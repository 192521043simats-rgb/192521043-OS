#include <stdio.h>

int main() {
    int n, i, t = 0, done = 0, bt[10], rt[10], pr[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("P%d Burst Time and Priority: ", i + 1);
        scanf("%d%d", &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    while(done < n) {
        int k = -1;

        for(i = 0; i < n; i++)
            if(rt[i] && (k == -1 || pr[i] < pr[k]))
                k = i;

        rt[k]--;
        printf("P%d ", k + 1);
        t++;

        if(rt[k] == 0)
            done++;
    }

    return 0;
}
