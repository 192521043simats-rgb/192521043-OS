#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *d = opendir(".");
    struct dirent *e;

    if(d == NULL) {
        perror("opendir");
        return 1;
    }

    while((e = readdir(d)) != NULL)
        if(e->d_name[0] != '.')
            printf("%s\n", e->d_name);

    closedir(d);
    return 0;
}