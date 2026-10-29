#include <stdio.h>

int main() {
    int p[30], f[10], n, m, i, j, k, x, far, faults = 0, hit;

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
            k = -1;
            for(j = 0; j < m; j++)
                if(f[j] == -1) { k = j; break; }

            if(k == -1) {
                far = -1;
                for(j = 0; j < m; j++) {
                    for(x = i + 1; x < n && p[x] != f[j]; x++);
                    if(x == n) { k = j; break; }
                    if(x > far) far = x, k = j;
                }
            }
            f[k] = p[i];
            faults++;
        }
    }

    printf("Page Faults = %d\n", faults);
    return 0;
}