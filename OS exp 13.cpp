#include <stdio.h>

int main() {
    int b[10], p[10], n, m, i, j, k, choice;

    printf("Enter number of blocks and processes: ");
    scanf("%d%d", &n, &m);

    printf("Enter block sizes: ");
    for(i = 0; i < n; i++) scanf("%d", &b[i]);

    printf("Enter process sizes: ");
    for(i = 0; i < m; i++) scanf("%d", &p[i]);

    printf("1.First Fit 2.Best Fit 3.Worst Fit: ");
    scanf("%d", &choice);

    for(i = 0; i < m; i++) {
        k = -1;
        for(j = 0; j < n; j++) {
            if(b[j] >= p[i] &&
               (k == -1 || (choice == 2 && b[j] < b[k]) ||
                (choice == 3 && b[j] > b[k]))) {
                k = j;
                if(choice == 1) break;
            }
        }
        if(k != -1) {
            printf("P%d -> Block %d\n", i + 1, k + 1);
            b[k] -= p[i];
        } else printf("P%d -> Not allocated\n", i + 1);
    }
    return 0;
}
