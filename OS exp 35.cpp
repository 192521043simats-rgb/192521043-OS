#include <stdio.h>

int main() {
    int index, n, b[20], i;

    printf("Enter index block: ");
    scanf("%d", &index);
    printf("Enter number of file blocks: ");
    scanf("%d", &n);

    printf("Enter data block numbers: ");
    for(i = 0; i < n; i++) scanf("%d", &b[i]);

    printf("Index Block: %d\n", index);
    for(i = 0; i < n; i++)
        printf("Entry %d -> Block %d\n", i + 1, b[i]);

    return 0;
}