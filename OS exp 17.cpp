#include <stdio.h>

int main() {
    int n, m, i, j, f = 0, work[10], avail[10];
    int alloc[10][10], need[10][10], max[10][10];
    int finish[10] = {0}, safe[10], count = 0;

    printf("Enter processes and resources: ");
    scanf("%d%d", &n, &m);

    printf("Enter Allocation matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++) scanf("%d",&alloc[i][j]);

    printf("Enter Maximum matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++) {
            scanf("%d",&max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }

    printf("Enter Available resources: ");
    for(j=0;j<m;j++) {
        scanf("%d",&avail[j]);
        work[j] = avail[j];
    }

    while(count < n) {
        f = 0;
        for(i=0;i<n;i++) {
            if(!finish[i]) {
                for(j=0;j<m;j++)
                    if(need[i][j] > work[j]) break;

                if(j == m) {
                    for(j=0;j<m;j++) work[j] += alloc[i][j];
                    safe[count++] = i;
                    finish[i] = 1;
                    f = 1;
                }
            }
        }
        if(!f) break;
    }

    if(count == n) {
        printf("Safe sequence: ");
        for(i=0;i<n;i++) printf("P%d ",safe[i]);
    } else printf("Unsafe state");

    return 0;
}