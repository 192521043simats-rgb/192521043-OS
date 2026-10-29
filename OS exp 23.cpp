#include <stdio.h>

int main() {
    int b[10], p[10], n, m, i, j;

    printf("Enter number of blocks and processes: ");
    scanf("%d%d", &n, &m);

    printf("Enter block sizes: ");
    for(i = 0; i < n; i++) scanf("%d", &b[i]);

    printf("Enter process sizes: ");
    for(i = 0; i < m; i++) scanf("%d", &p[i]);

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++)
            if(b[j] >= p[i]) break;

        if(j < n) {
            printf("P%d -> B%d\n", i + 1, j + 1);
            b[j] -= p[i];
        } else
            printf("P%d -> Not Allocated\n", i + 1);
    }
    return 0;
}