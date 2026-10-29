#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    struct stat s;

    FILE *f = fopen("sample.txt", "w");
    if (f == NULL) {
        perror("File creation failed");
        return 1;
    }
    fprintf(f, "Hello Linux");
    fclose(f);

    chmod("sample.txt", 0754);

    if (stat("sample.txt", &s) == 0) {
        printf("File: sample.txt\n");
        printf("Owner: rwx\n");
        printf("Group: r-x\n");
        printf("Others: r--\n");
        printf("Permission: %03o\n", s.st_mode & 0777);
    }

    return 0;
}