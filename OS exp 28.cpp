#include <stdio.h>
#include <string.h>

int main() {
    FILE *f;
    char filename[100], key[50], line[200];

    printf("Enter filename: ");
    scanf("%99s", filename);

    f = fopen(filename, "r");
    if(f == NULL) {
        printf("File not found\n");
        return 1;
    }

    printf("Enter search word: ");
    scanf("%49s", key);

    while(fgets(line, sizeof(line), f))
        if(strstr(line, key))
            printf("%s", line);

    fclose(f);
    return 0;
}