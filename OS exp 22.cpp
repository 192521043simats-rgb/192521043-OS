#include <stdio.h>

int main() {
    int b[10], p[10], n, m, i, j, k;

    printf("Enter number of blocks and processes: ");
    scanf("%d%d", &n, &m);

    printf("Enter block sizes: ");
    for(i = 0; i < n; i++) scanf("%d", &b[i]);

    printf("Enter process sizes: ");
    for(i = 0; i < m; i++) scanf("%d", &p[i]);

    for(i = 0; i < m; i++) {
        k = -1;
        for(j = 0; j < n; j++)
            if(b[j] >= p[i] && (k == -1 || b[j] < b[k]))
                k = j;

        if(k != -1) {
            printf("P%d -> B%d\n", i + 1, k + 1);
            b[k] -= p[i];
        } else
            printf("P%d -> Not Allocated\n", i + 1);
    }
    return 0;
}