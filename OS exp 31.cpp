#include <stdio.h>

int main() {
    int p[30], f[10], n, m, i, j, k = 0, faults = 0, hit;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string: ");
    for(i = 0; i < n; i++) scanf("%d", &p[i]);

    printf("Enter number of frames: ");
    scanf("%d", &m);
    for(i = 0; i < m; i++) f[i] = -1;

    for(i = 0; i < n; i++) {
        hit = 0;
        for(j = 0; j < m; j++)
            if(f[j] == p[i]) hit = 1;

        if(!hit) {
            f[k] = p[i];
            k = (k + 1) % m;
            faults++;
        }

        printf("%d: ", p[i]);
        for(j = 0; j < m; j++)
            if(f[j] != -1) printf("%d ", f[j]);
        printf("\n");
    }

    printf("Page Faults = %d\n", faults);
    return 0;
}