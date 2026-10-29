#include <stdio.h>

int main() {
    int p[30], f[10], t[10], n, m, i, j, k, time = 0, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string: ");
    for(i = 0; i < n; i++) scanf("%d", &p[i]);
    printf("Enter number of frames: ");
    scanf("%d", &m);

    for(i = 0; i < m; i++) f[i] = -1, t[i] = 0;

    for(i = 0; i < n; i++) {
        time++;
        for(j = 0; j < m; j++)
            if(f[j] == p[i]) break;

        if(j == m) {
            k = 0;
            for(j = 0; j < m; j++)
                if(f[j] == -1) { k = j; break; }
                else if(t[j] < t[k]) k = j;
            f[k] = p[i];
            faults++;
        } else k = j;

        t[k] = time;
    }

    printf("Page Faults = %d\n", faults);
    return 0;
}