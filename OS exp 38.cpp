#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[20], n, h, i, j, t, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);
    printf("Enter request queue: ");
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter head position: ");
    scanf("%d", &h);

    for(i = 0; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
            if(a[i] > a[j]) {
                t = a[i]; a[i] = a[j]; a[j] = t;
            }

    printf("Head movement: %d", h);
    for(i = 0; i < n; i++)
        if(a[i] >= h) {
            total += abs(h - a[i]);
            h = a[i];
            printf(" -> %d", h);
        }

    total += abs(h - 199);
    h = 199;
    printf(" -> %d", h);

    for(i = n - 1; i >= 0; i--)
        if(a[i] < h) {
            total += abs(h - a[i]);
            h = a[i];
            printf(" -> %d", h);
        }

    printf("\nTotal head movement = %d\n", total);
    return 0;
}