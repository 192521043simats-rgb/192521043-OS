
#include <stdio.h>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    int fd;
    struct _stat s;

    FILE *f = fopen("a.txt", "w");
    if (f == NULL) {
        printf("File creation failed\n");
        return 1;
    }

    fprintf(f, "Hello World!");
    fclose(f);

    fd = _open("a.txt", _O_RDONLY);

    if (fd != -1) {
        printf("File opened successfully\n");
        printf("File descriptor: %d\n", fd);
        printf("File position: %ld\n", (long)_lseek(fd, 0, SEEK_CUR));

        if (_fstat(fd, &s) == 0)
            printf("File size: %ld bytes\n", (long)s.st_size);

        _close(fd);
    } else {
        printf("File opening failed\n");
    }

    printf("\nDirectory files:\n");

    WIN32_FIND_DATA data;
    HANDLE h = FindFirstFile("*", &data);

    if (h != INVALID_HANDLE_VALUE) {
        do {
            printf("%s\n", data.cFileName);
        } while (FindNextFile(h, &data));

        FindClose(h);
    }

    return 0;
}
