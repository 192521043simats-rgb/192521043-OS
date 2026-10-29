#include <stdio.h>

int main() {
    FILE *f;
    char s[100];

    f = fopen("file.txt", "w");
    if(f == NULL) return 1;
    fprintf(f, "Hello World");
    fclose(f);
    printf("File created\n");

    f = fopen("file.txt", "r");
    if(f == NULL) return 1;
    fgets(s, sizeof(s), f);
    printf("Content: %s\n", s);
    fclose(f);

    f = fopen("file.txt", "a");
    if(f == NULL) return 1;
    fprintf(f, "\nWelcome");
    fclose(f);
    printf("Content appended\n");

    if(remove("file.txt") == 0)
        printf("File deleted\n");

    return 0;
}