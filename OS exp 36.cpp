#include <stdio.h>

int main() {
    int b[20], n, i;

    printf("Enter number of blocks: ");
    scanf("%d", &n);
    printf("Enter block numbers: ");
    for(i = 0; i < n; i++) scanf("%d", &b[i]);

    printf("First Block: %d\n", b[0]);
    for(i = 0; i < n - 1; i++)
        printf("%d -> %d\n", b[i], b[i + 1]);
    printf("Last Block: %d -> NULL\n", b[n - 1]);

    return 0;
}